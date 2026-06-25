// ADS Qt Monitor — live TwinCAT PLC variable monitor over ADS for Linux.
//
// Copyright (c) 2026 Brenno Domingues <brennohdomingues@gmail.com>
// GitHub: https://github.com/BrennoDom
//
// SPDX-License-Identifier: MIT
// Licensed under the MIT License; see the LICENSE file in the project root.

#include "plc_monitor_window.h"
#include "standard_types.h"

#include <QHeaderView>
#include <QMessageBox>
#include <QApplication>
#include <QStatusBar>
#include <QStringList>
#include <QEvent>
#include <QEventLoop>
#include <QKeyEvent>
#include <QColor>
#include <QTimer>
#include <QLineEdit>
#include <QComboBox>
#include <QPalette>
#include <QStyledItemDelegate>
#include <QPainter>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>

#include <cstdio>
#include <map>
#include <limits>
#include <cmath>
namespace {
constexpr int kInvalidRole = Qt::UserRole + 5;
constexpr int kStructRole = StructTree::kStructRole;

class ValueItemDelegate : public QStyledItemDelegate {
public:
  explicit ValueItemDelegate(const StructTree* tree, QObject* parent = nullptr)
    : QStyledItemDelegate(parent), tree_(tree) {}

  QWidget* createEditor(QWidget* parent, const QStyleOptionViewItem& option,
                        const QModelIndex& index) const override
  {
    // Enum, BOOL and BIT cells get a dropdown of their valid values instead of a
    // free text field.
    const std::string type = index.sibling(index.row(), 1).data().toString().toStdString();
    QStringList options;
    if (tree_ && tree_->isEnum(type)) {
      for (const auto& e : tree_->enumEntries(type)) {
        options << QString::fromStdString(e.second);
      }
    } else if (type == "BOOL" || type == "BIT") {
      options << "FALSE" << "TRUE";
    }
    if (!options.isEmpty()) {
      auto* combo = new QComboBox(parent);
      combo->addItems(options);
      // Commit and close as soon as the user picks a value.
      auto* self = const_cast<ValueItemDelegate*>(this);
      connect(combo, QOverload<int>::of(&QComboBox::activated), self,
              [self, combo](int) {
                emit self->commitData(combo);
                emit self->closeEditor(combo);
              });
      return combo;
    }

    auto* editor = QStyledItemDelegate::createEditor(parent, option, index);
    auto* line = qobject_cast<QLineEdit*>(editor);
    if (line) {
      line->setFrame(false);
      line->setAutoFillBackground(true);
      line->setTextMargins(0, 0, 0, 0);
      applyEditorPalette(line, index.data(kInvalidRole).toBool());
    }
    return editor;
  }

  void setEditorData(QWidget* editor, const QModelIndex& index) const override
  {
    if (auto* combo = qobject_cast<QComboBox*>(editor)) {
      const int i = combo->findText(index.data(Qt::EditRole).toString());
      if (i >= 0) combo->setCurrentIndex(i);
      return;
    }
    QStyledItemDelegate::setEditorData(editor, index);
    auto* line = qobject_cast<QLineEdit*>(editor);
    if (line) {
      applyEditorPalette(line, index.data(kInvalidRole).toBool());
    }
  }

  void setModelData(QWidget* editor, QAbstractItemModel* model,
                    const QModelIndex& index) const override
  {
    if (auto* combo = qobject_cast<QComboBox*>(editor)) {
      model->setData(index, combo->currentText(), Qt::EditRole);
      return;
    }
    QStyledItemDelegate::setModelData(editor, model, index);
  }

  void updateEditorGeometry(QWidget* editor, const QStyleOptionViewItem& option,
                            const QModelIndex& index) const override
  {
    Q_UNUSED(index);
    editor->setGeometry(option.rect);
  }

  void paint(QPainter* painter, const QStyleOptionViewItem& option,
             const QModelIndex& index) const override
  {
    if (index.data(kInvalidRole).toBool()) {
      painter->save();
      painter->fillRect(option.rect, QColor(255, 120, 120));
      painter->restore();
    }
    QStyledItemDelegate::paint(painter, option, index);
  }

private:
  const StructTree* tree_ = nullptr;

  static void applyEditorPalette(QLineEdit* line, bool invalid)
  {
    if (!line) return;
    auto pal = line->palette();
    if (invalid) {
      pal.setColor(QPalette::Base, QColor(255, 120, 120));
    } else {
      pal.setColor(QPalette::Base, QColor(Qt::white));
    }
    line->setPalette(pal);
  }
};



void applyEditorErrorStyle(QTreeWidget* table, bool enabled)
{
  if (!table) return;
  auto* editor = table->findChild<QLineEdit*>();
  if (!editor) return;
  auto pal = editor->palette();
  if (enabled) {
    pal.setColor(QPalette::Base, QColor(255, 120, 120));
  } else {
    pal.setColor(QPalette::Base, QColor(Qt::white));
  }
  editor->setPalette(pal);
}
} // namespace

PlcMonitorWindow::PlcMonitorWindow(QWidget* parent)
  : QMainWindow(parent),
    table_(new QTreeWidget(this)),
    timer_(new QTimer(this)),
    run_button_(new QPushButton("RUN", this)),
    config_button_(new QPushButton("CONFIG", this)),
    netid_{127, 0, 0, 1, 1, 1},
    ip_("127.0.0.1"),
    ams_port_(851),
    updating_(false),
    pending_bool_item_(nullptr),
    pending_invalid_item_(nullptr),
    polling_suspended_(false),
    run_reconnect_attempts_(0)
{
  setWindowTitle("ADS PLC Monitor");
  auto* container = new QWidget(this);
  auto* layout = new QVBoxLayout(container);
  auto* controls = new QHBoxLayout();
  controls->addWidget(run_button_);
  controls->addWidget(config_button_);
  controls->addStretch();
  layout->addLayout(controls);
  layout->addWidget(table_);
  layout->setContentsMargins(6, 6, 6, 6);
  setCentralWidget(container);

  setupTable();

  // Don't block the constructor on the PLC load — show the window first, then
  // fetch symbols/types in initialLoadTypes so the UI appears immediately.
  statusBar()->showMessage("Loading variables from PLC...");

  connect(timer_, &QTimer::timeout, this, &PlcMonitorWindow::refreshValues);
  connect(table_, &QTreeWidget::itemChanged, this, &PlcMonitorWindow::onItemChanged);
  connect(table_, &QTreeWidget::itemDoubleClicked, this, &PlcMonitorWindow::onItemDoubleClicked);
  connect(run_button_, &QPushButton::clicked, this, &PlcMonitorWindow::onSetRun);
  connect(config_button_, &QPushButton::clicked, this, &PlcMonitorWindow::onSetConfig);
  table_->installEventFilter(this);

  QTimer::singleShot(0, this, &PlcMonitorWindow::initialLoadTypes);
}

void PlcMonitorWindow::setupTable()
{
  table_->setColumnCount(4);
  table_->setHeaderLabels(QStringList() << "Name" << "Type" << "Value" << "Size");
  table_->header()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
  table_->header()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
  table_->header()->setSectionResizeMode(2, QHeaderView::Stretch);
  table_->header()->setSectionResizeMode(3, QHeaderView::ResizeToContents);
  table_->setRootIsDecorated(true);
  table_->setItemsExpandable(true);
  table_->setExpandsOnDoubleClick(true);
  table_->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::EditKeyPressed);
  table_->setSelectionMode(QAbstractItemView::NoSelection);
  table_->setItemDelegateForColumn(2, new ValueItemDelegate(&struct_tree_, table_));
  table_->viewport()->installEventFilter(this);
}


void PlcMonitorWindow::revertInvalidEdit(const QString& message)
{
  if (!pending_invalid_item_) return;
  updating_ = true;
  pending_invalid_item_->setText(2, pending_invalid_prev_value_);
  pending_invalid_item_->setData(2, kInvalidRole, false);
  pending_invalid_item_->setToolTip(2, QString());
  applyEditorErrorStyle(table_, false);
  table_->closePersistentEditor(pending_invalid_item_, 2);
  updating_ = false;
  pending_invalid_item_ = nullptr;
  if (!message.isEmpty()) {
    statusBar()->showMessage(message);
  }
}

void PlcMonitorWindow::initialLoadTypes()
{
  // Phase 1: just show the message and let the event loop fully paint the window.
  // The actual (blocking) fetch runs in deferredLoad on the next tick, so the user
  // sees a rendered window with the message instead of a black, unpainted screen.
  statusBar()->showMessage("Fetching variables from PLC...");
  QTimer::singleShot(50, this, &PlcMonitorWindow::deferredLoad);
}

void PlcMonitorWindow::deferredLoad()
{
  ensureConnected();
  if (struct_tree_.isLoaded()) {
    statusBar()->showMessage(
        QString("Loaded %1 variables").arg(client_.symbols().size()), 4000);
    refreshValues();
  } else {
    statusBar()->showMessage("Waiting for PLC connection...");
  }
  timer_->start(250);
}

void PlcMonitorWindow::refreshValues()
{
  if (polling_suspended_) {
    return;
  }
  if (!ensureConnected()) {
    const auto msg = client_.lastError();
    statusBar()->showMessage(QString::fromStdString(msg));
    fprintf(stderr, "[ADS] %s\n", msg.c_str());
    return;
  }
  if (!struct_tree_.isLoaded()) return;

  std::vector<std::string> values;
  std::vector<std::vector<uint8_t>> raw;
  std::string error;
  if (!client_.readAllDetailed(values, raw, error)) {
    statusBar()->showMessage(QString::fromStdString(error));
    fprintf(stderr, "[ADS] %s\n", error.c_str());
    client_.disconnect();
    return;
  }

  last_raw_values_ = std::move(raw);
  updateTable(values);
}

void PlcMonitorWindow::onSetRun()
{
  if (!ensureTransportConnected()) {
    statusBar()->showMessage("Falha ao conectar ao ADS");
    return;
  }

  std::string error;
  if (!client_.setRuntimeState(PlcClient::RuntimeState::Run, error)) {
    statusBar()->showMessage(QString::fromStdString(error));
    return;
  }
  client_.disconnect();
  run_reconnect_attempts_ = 0;
  suspendPolling("Aguardando PLC entrar em RUN...");
  QTimer::singleShot(300, this, &PlcMonitorWindow::tryReconnectAfterRun);
}

void PlcMonitorWindow::tryReconnectAfterRun()
{
  ++run_reconnect_attempts_;
  if (ensureConnected()) {
    resumePolling();
    refreshValues();
    statusBar()->showMessage("Runtime em RUN");
    return;
  }

  if (run_reconnect_attempts_ < 10) {
    QTimer::singleShot(300, this, &PlcMonitorWindow::tryReconnectAfterRun);
  } else {
    statusBar()->showMessage("Falha ao reconectar após RUN");
  }
}

void PlcMonitorWindow::onSetConfig()
{
  if (!ensureTransportConnected()) {
    statusBar()->showMessage("Falha ao conectar ao ADS");
    return;
  }

  std::string error;
  if (!client_.setRuntimeState(PlcClient::RuntimeState::Config, error)) {
    statusBar()->showMessage(QString::fromStdString(error));
    return;
  }
  suspendPolling("Runtime em CONFIG");
  statusBar()->showMessage("Runtime em CONFIG");
}

void PlcMonitorWindow::updateTable(const std::vector<std::string>& values)
{
  updating_ = true;
  const auto& syms = client_.symbols();
  for (int i = 0; i < (int)values.size() && i < (int)value_items_.size(); ++i) {
    auto* item = value_items_[i];
    std::string display_value = values[i];
    if (i < (int)last_raw_values_.size() && !last_raw_values_[i].empty() && i < (int)syms.size()) {
      std::string enum_str;
      if (struct_tree_.formatEnumValue(syms[i].type, last_raw_values_[i].data(),
                                       last_raw_values_[i].size(), enum_str)) {
        display_value = enum_str;
      } else {
        const auto resolved = struct_tree_.resolveTypeName(syms[i].type);
        if (!resolved.empty() && resolved != syms[i].type) {
          display_value = client_.formatTypeValue(resolved,
                                                  last_raw_values_[i].data(),
                                                  (uint32_t)last_raw_values_[i].size());
        }
      }
    }
    if (item) {
      if (pending_bool_item_ != item) {
        item->setText(2, QString::fromStdString(display_value));
      }
      item->setData(0, Qt::UserRole + 4, QString::fromStdString(display_value));
    }

    if (i < (int)array_children_items_.size() && !array_children_items_[i].empty()
        && item && item->isExpanded()) {
      const auto& v = display_value;
      size_t pos = 0;
      size_t child_index = 0;
      while (pos < v.size() && child_index < array_children_items_[i].size()) {
        size_t lb = v.find('[', pos);
        if (lb == std::string::npos) break;
        size_t rb = v.find("]=", lb);
        if (rb == std::string::npos) break;
        size_t val_start = rb + 2;
        size_t next = v.find(", ", val_start);
        std::string val = (next == std::string::npos)
          ? v.substr(val_start)
          : v.substr(val_start, next - val_start);

        if (pending_bool_item_ != array_children_items_[i][child_index]) {
          array_children_items_[i][child_index]->setText(2, QString::fromStdString(val));
        }
        array_children_items_[i][child_index]->setData(0, Qt::UserRole + 4, QString::fromStdString(val));
        ++child_index;
        if (next == std::string::npos) break;
        pos = next + 2;
      }
    }

  }
  struct_tree_.updateValues(last_raw_values_, client_);
  updating_ = false;
}

bool PlcMonitorWindow::ensureConnected()
{
  if (!ensureTransportConnected()) return false;

  if (client_.symbols().empty()) {
    if (!client_.loadSymbols()) {
      if (isTargetPortMissing(client_.lastError())) {
        suspendPolling("PLC em CONFIG (porta ADS indisponível)");
      }
      return false;
    }
    struct_tree_.loadFromPlc(client_.port(), &client_.ams());
    const auto& syms = client_.symbols();
    std::vector<uint32_t> overrides(syms.size(), 0);
    for (size_t i = 0; i < syms.size(); ++i) {
      const size_t expected = struct_tree_.typeSize(syms[i].type);
      if (expected > syms[i].size) {
        overrides[i] = static_cast<uint32_t>(expected);
      }
    }
    client_.setReadLengthOverrides(overrides);
    if (!client_.buildSumRead()) {
      return false;
    }

    updating_ = true;
    table_->clear();
    setupTable();
    value_items_.assign(client_.symbols().size(), nullptr);
    array_children_items_.assign(client_.symbols().size(), {});
    struct_tree_.clear(client_.symbols().size());
    symbol_index_by_name_.clear();

    std::map<std::string, QTreeWidgetItem*> group_items;

    for (int i = 0; i < (int)syms.size(); ++i) {
      symbol_index_by_name_[syms[i].name] = i;
    }

    auto ends_with = [](const std::string& s, const std::string& suffix) {
      return s.size() >= suffix.size() && s.compare(s.size() - suffix.size(), suffix.size(), suffix) == 0;
    };

    // Display name without the group prefix: "SAFE.bAck" -> "bAck". The full
    // symbol name is kept everywhere else (lookups, writes, child binding).
    auto strip_group = [](const std::string& n) {
      const auto d = n.find('.');
      return d == std::string::npos ? n : n.substr(d + 1);
    };

    for (int i = 0; i < (int)syms.size(); ++i) {
      // Keep the event loop alive during the (potentially multi-second) tree build
      // so the window manager doesn't flag the app as "not responding". User input
      // is excluded to avoid re-entering this code mid-build.
      if ((i & 63) == 0) {
        statusBar()->showMessage(
            QString("Loading variables... %1/%2").arg(i).arg((int)syms.size()));
        qApp->processEvents(QEventLoop::ExcludeUserInputEvents);
      }
      const auto& sym_name = syms[i].name;
      if (hasParentSymbol(sym_name)) {
        continue;
      }
      if (struct_tree_.shouldSkipSymbol(syms, symbol_index_by_name_, i)) {
        continue;
      }

      const auto group = groupForSymbol(syms[i].name);
      QTreeWidgetItem* group_item = nullptr;
      auto it = group_items.find(group);
      if (it == group_items.end()) {
        group_item = new QTreeWidgetItem(table_);
        group_item->setText(0, QString::fromStdString(group));
        group_item->setExpanded(true);
        group_items[group] = group_item;
      } else {
        group_item = it->second;
      }

      auto* item = new QTreeWidgetItem(group_item);
      item->setText(0, QString::fromStdString(strip_group(syms[i].name)));
      item->setText(1, QString::fromStdString(syms[i].type));
      item->setText(2, QStringLiteral(""));
      item->setText(3, QString::number(syms[i].size));
      value_items_[i] = item;

      item->setData(0, Qt::UserRole, i);
      item->setData(0, Qt::UserRole + 1, 0);
      item->setData(0, Qt::UserRole + 2, QString::fromStdString(syms[i].type));
      item->setData(0, Qt::UserRole + 3, false);
      item->setData(0, Qt::UserRole + 4, QString());

      const bool symbol_tree = addSymbolChildren(syms, i, item);
      const bool tc2_tree = struct_tree_.addChildrenForSymbol(syms, symbol_index_by_name_, i, item);
      if (symbol_tree || tc2_tree) {
        // handled by symbol tree and/or tc2_mc2 monitor
      } else if (syms[i].type.rfind("ARRAY", 0) == 0) {
        long long lower = 0;
        long long upper = -1;
        if (parseArrayBounds(syms[i].type, lower, upper) && upper >= lower) {
          std::string elem_type = syms[i].type;
          size_t of_pos = syms[i].type.find("OF ");
          if (of_pos != std::string::npos) {
            elem_type = syms[i].type.substr(of_pos + 3);
          }
          const auto count = (size_t)(upper - lower + 1);
          array_children_items_[i].reserve(count);
          for (size_t idx = 0; idx < count; ++idx) {
            auto* child = new QTreeWidgetItem(item);
            const auto element_name = strip_group(syms[i].name) + "[" + std::to_string(lower + (long long)idx) + "]";
            child->setText(0, QString::fromStdString(element_name));
            child->setText(1, QString::fromStdString(elem_type));
            child->setText(2, QStringLiteral(""));
            child->setText(3, QStringLiteral(""));
            array_children_items_[i].push_back(child);

            child->setData(0, Qt::UserRole, i);
            child->setData(0, Qt::UserRole + 1, (long long)idx);
            child->setData(0, Qt::UserRole + 2, QString::fromStdString(elem_type));
            child->setData(0, Qt::UserRole + 3, true);
            child->setData(0, Qt::UserRole + 4, QString());
            child->setFlags(child->flags() | Qt::ItemIsEditable);
          }
          item->setExpanded(false);
          item->setFlags(item->flags() & ~Qt::ItemIsEditable);
        }
      } else {
        item->setFlags(item->flags() | Qt::ItemIsEditable);
        if (syms[i].type == "AXIS_REF") {
          item->setFlags(item->flags() & ~Qt::ItemIsEditable);
        }
      }
    }
    updating_ = false;
  }

  return true;
}

bool PlcMonitorWindow::ensureTransportConnected()
{
  if (!client_.isConnected()) {
    if (!client_.connect(netid_, ip_, ams_port_)) {
      return false;
    }
  }
  return true;
}

void PlcMonitorWindow::suspendPolling(const QString& message)
{
  if (polling_suspended_) return;
  polling_suspended_ = true;
  timer_->stop();
  statusBar()->showMessage(message);
}

void PlcMonitorWindow::resumePolling()
{
  if (!polling_suspended_) return;
  polling_suspended_ = false;
  timer_->start(250);
}

bool PlcMonitorWindow::isTargetPortMissing(const std::string& message) const
{
  return message.find("failed: 6") != std::string::npos ||
         message.find(" 6") != std::string::npos;
}

bool PlcMonitorWindow::parseArrayBounds(const std::string& type, long long& lower, long long& upper) const
{
  size_t lb = type.find('[');
  size_t rb = type.find(']');
  size_t dots = type.find("..", lb);
  if (lb == std::string::npos || rb == std::string::npos || dots == std::string::npos) {
    return false;
  }
  lower = std::strtoll(type.substr(lb + 1, dots - (lb + 1)).c_str(), nullptr, 10);
  upper = std::strtoll(type.substr(dots + 2, rb - (dots + 2)).c_str(), nullptr, 10);
  return true;
}

bool PlcMonitorWindow::hasParentSymbol(const std::string& name) const
{
  // Walk up the symbol path, stripping one trailing segment at a time. A segment
  // is either a ".field" member or an "[index]" array element, so that flat
  // element symbols such as "GVL_JOINT_STATUS[0].Position" are recognised as
  // children of the array symbol "GVL_JOINT_STATUS" (which we expand ourselves)
  // and not re-added as duplicate top-level rows.
  std::string cur = name;
  while (true) {
    const auto dot = cur.rfind('.');
    const auto br = cur.rfind('[');
    size_t cut = std::string::npos;
    if (dot != std::string::npos && (br == std::string::npos || dot > br)) {
      cut = dot;
    } else if (br != std::string::npos) {
      cut = br;
    }
    if (cut == std::string::npos) break;
    cur = cur.substr(0, cut);
    if (symbol_index_by_name_.find(cur) != symbol_index_by_name_.end()) return true;
  }
  return false;
}

bool PlcMonitorWindow::addSymbolChildren(const std::vector<SymbolEntry>& syms,
                                         int parent_index,
                                         QTreeWidgetItem* parent)
{
  if (parent_index < 0 || parent_index >= (int)syms.size()) return false;
  const std::string base = syms[parent_index].name;
  const std::string prefix = base + ".";
  bool added = false;

  auto findChild = [&](QTreeWidgetItem* node, const std::string& name) -> QTreeWidgetItem* {
    for (int i = 0; i < node->childCount(); ++i) {
      auto* ch = node->child(i);
      if (ch && ch->text(0).toStdString() == name) return ch;
    }
    return nullptr;
  };

  auto ensureNode = [&](QTreeWidgetItem* node, const std::string& name, const std::string& full_name) -> QTreeWidgetItem* {
    if (auto* existing = findChild(node, name)) return existing;
    auto* created = new QTreeWidgetItem(node);
    created->setText(0, QString::fromStdString(name));
    created->setText(1, QStringLiteral(""));
    created->setText(2, QStringLiteral(""));
    created->setText(3, QStringLiteral(""));
    created->setFlags(created->flags() & ~Qt::ItemIsEditable);

    auto it = symbol_index_by_name_.find(full_name);
    if (it != symbol_index_by_name_.end()) {
      const int idx = it->second;
      created->setText(1, QString::fromStdString(syms[idx].type));
      created->setText(3, QString::number(syms[idx].size));
      created->setData(0, Qt::UserRole, idx);
      created->setData(0, Qt::UserRole + 1, 0);
      created->setData(0, Qt::UserRole + 2, QString::fromStdString(syms[idx].type));
      created->setData(0, Qt::UserRole + 3, false);
      created->setData(0, Qt::UserRole + 4, QString());
      value_items_[idx] = created;
    } else {
      created->setData(0, Qt::UserRole, -1);
    }

    return created;
  };

  for (int i = 0; i < (int)syms.size(); ++i) {
    const auto& full = syms[i].name;
    if (full.rfind(prefix, 0) != 0) continue;
    const auto rest = full.substr(prefix.size());
    if (rest.empty()) continue;

    std::vector<std::string> parts;
    size_t start = 0;
    while (start < rest.size()) {
      auto dot = rest.find('.', start);
      if (dot == std::string::npos) {
        parts.push_back(rest.substr(start));
        break;
      }
      parts.push_back(rest.substr(start, dot - start));
      start = dot + 1;
    }
    if (parts.empty()) continue;

    QTreeWidgetItem* current = parent;
    std::string current_name = base;
    for (size_t p = 0; p < parts.size(); ++p) {
      current_name += "." + parts[p];
      current = ensureNode(current, parts[p], current_name);
    }

    current->setText(1, QString::fromStdString(syms[i].type));
    current->setText(3, QString::number(syms[i].size));
    current->setData(0, Qt::UserRole, i);
    current->setData(0, Qt::UserRole + 1, 0);
    current->setData(0, Qt::UserRole + 2, QString::fromStdString(syms[i].type));
    current->setData(0, Qt::UserRole + 3, false);
    current->setData(0, Qt::UserRole + 4, QString());
    value_items_[i] = current;
    added = true;

    bool expanded = false;
    bool has_symbol_children = false;
    const std::string child_prefix = syms[i].name + ".";
    for (int k = 0; k < (int)syms.size(); ++k) {
      if (k == i) continue;
      if (syms[k].name.rfind(child_prefix, 0) == 0) {
        has_symbol_children = true;
        break;
      }
    }
    if (!has_symbol_children && current->childCount() == 0) {
      expanded = struct_tree_.addChildrenForSymbol(syms, symbol_index_by_name_, i, current);
    }

    const auto resolved_type = struct_tree_.resolveTypeName(syms[i].type);
    if (!expanded && resolved_type.rfind("ARRAY", 0) == 0) {
      long long lower = 0;
      long long upper = -1;
      if (parseArrayBounds(resolved_type, lower, upper) && upper >= lower) {
        std::string elem_type = resolved_type;
        size_t of_pos = resolved_type.find("OF ");
        if (of_pos != std::string::npos) {
          elem_type = resolved_type.substr(of_pos + 3);
        }
        const auto count = (size_t)(upper - lower + 1);
        array_children_items_[i].reserve(count);
        for (size_t idx = 0; idx < count; ++idx) {
          auto* elem = new QTreeWidgetItem(current);
          elem->setText(0, QString::fromStdString("[" + std::to_string(lower + (long long)idx) + "]"));
          elem->setText(1, QString::fromStdString(elem_type));
          elem->setText(2, QStringLiteral(""));
          elem->setText(3, QStringLiteral(""));
          array_children_items_[i].push_back(elem);

          elem->setData(0, Qt::UserRole, i);
          elem->setData(0, Qt::UserRole + 1, (long long)idx);
          elem->setData(0, Qt::UserRole + 2, QString::fromStdString(elem_type));
          elem->setData(0, Qt::UserRole + 3, true);
          elem->setData(0, Qt::UserRole + 4, QString());
          elem->setFlags(elem->flags() | Qt::ItemIsEditable);
        }
        current->setExpanded(false);
        current->setFlags(current->flags() & ~Qt::ItemIsEditable);
      }
    } else if (!expanded) {
      if (syms[i].type == "AXIS_REF") {
        current->setFlags(current->flags() & ~Qt::ItemIsEditable);
      } else {
        current->setFlags(current->flags() | Qt::ItemIsEditable);
      }
    }
  }

  if (added) {
    parent->setFlags(parent->flags() & ~Qt::ItemIsEditable);
    parent->setExpanded(false);
  }

  return added;
}

void PlcMonitorWindow::onItemChanged(QTreeWidgetItem* item, int column)
{
  if (updating_ || column != 2 || !item) return;

  if (struct_tree_.isStructItem(item)) {
    const auto type = item->text(1).toStdString();
    // Enum/BOOL/BIT cells are edited via a dropdown, so the value is always valid
    // — skip the numeric validation used for plain fields.
    const bool combo_cell = struct_tree_.isEnum(type) || type == "BOOL" || type == "BIT";
    if (!combo_cell) {
      const auto result = tc_standard::validateInput(type, item->text(2).toStdString());
      if (!result.ok) {
        statusBar()->showMessage(QString::fromStdString(result.error));
        updating_ = true;
        item->setData(2, kInvalidRole, true);
        item->setToolTip(2, QString::fromStdString(result.error));
        pending_invalid_item_ = item;
        pending_invalid_prev_value_ = item->data(0, Qt::UserRole + 4).toString();
        table_->setCurrentItem(item, 2);
        QTimer::singleShot(0, this, [this, item]() {
          if (item) {
            table_->openPersistentEditor(item, 2);
            table_->setFocus();
            applyEditorErrorStyle(table_, true);
            if (auto* editor = table_->findChild<QLineEdit*>()) {
              editor->installEventFilter(this);
            }
          }
        });
        updating_ = false;
        return;
      }
    }

    std::string error;
    if (!struct_tree_.handleEdit(item, client_, last_raw_values_, error)) {
      statusBar()->showMessage(QString::fromStdString(error));
      updating_ = true;
      item->setData(2, kInvalidRole, true);
      item->setToolTip(2, QString::fromStdString(error));
      pending_invalid_item_ = item;
      pending_invalid_prev_value_ = item->data(0, Qt::UserRole + 4).toString();
      table_->setCurrentItem(item, 2);
      QTimer::singleShot(0, this, [this, item]() {
        if (item) {
          table_->openPersistentEditor(item, 2);
          table_->setFocus();
          applyEditorErrorStyle(table_, true);
          if (auto* editor = table_->findChild<QLineEdit*>()) {
            editor->installEventFilter(this);
          }
        }
      });
      updating_ = false;
      return;
    }

    item->setData(0, Qt::UserRole + 4, item->text(2));
    item->setData(2, kInvalidRole, false);
    item->setToolTip(2, QString());
    applyEditorErrorStyle(table_, false);
    table_->closePersistentEditor(item, 2);
    if (pending_invalid_item_ == item) {
      pending_invalid_item_ = nullptr;
    }
    return;
  }

  const auto sym_index = item->data(0, Qt::UserRole).toInt();
  if (sym_index < 0) return;
  const auto type = item->data(0, Qt::UserRole + 2).toString().toStdString();
  if (type == "BOOL" && pending_bool_item_ == item) {
    return;
  }

  if (!struct_tree_.isEnum(type) && type != "BOOL" && type != "BIT") {
  const auto result = tc_standard::validateInput(type, item->text(2).toStdString());
  if (!result.ok) {
    statusBar()->showMessage(QString::fromStdString(result.error));
    updating_ = true;
    item->setData(2, kInvalidRole, true);
    item->setToolTip(2, QString::fromStdString(result.error));
    pending_invalid_item_ = item;
    pending_invalid_prev_value_ = item->data(0, Qt::UserRole + 4).toString();
    table_->setCurrentItem(item, 2);
    QTimer::singleShot(0, this, [this, item]() {
      if (item) {
        table_->openPersistentEditor(item, 2);
        table_->setFocus();
        applyEditorErrorStyle(table_, true);
        if (auto* editor = table_->findChild<QLineEdit*>()) {
          editor->installEventFilter(this);
        }
      }
    });
    updating_ = false;
    return;
  }
  }  // end of non-enum validation guard

  const auto element_offset = item->data(0, Qt::UserRole + 1).toLongLong();
  const auto is_array_elem = item->data(0, Qt::UserRole + 3).toBool();

  std::string error;
  bool write_ok;
  if (struct_tree_.isEnum(type)) {
    // The cell holds the selected state name; write its integer value as the
    // underlying base type.
    long long ev = 0;
    if (!struct_tree_.enumNameToValue(type, item->text(2).toStdString(), ev)) {
      write_ok = false;
      error = "Unknown enum value";
    } else {
      const auto base = struct_tree_.resolveTypeName(type);
      const size_t bsz = struct_tree_.typeSize(type);
      const size_t byte_off = is_array_elem ? (size_t)(element_offset * (long long)bsz) : 0u;
      write_ok = client_.writeByOffset(static_cast<size_t>(sym_index), byte_off, bsz,
                                       base, std::to_string(ev), error);
    }
  } else {
    write_ok = client_.writeValue(
        static_cast<size_t>(sym_index),
        item->text(2).toStdString(),
        error,
        is_array_elem,
        element_offset,
        type);
  }
  if (!write_ok) {
    statusBar()->showMessage(QString::fromStdString(error));
    updating_ = true;
    item->setData(2, kInvalidRole, true);
    item->setToolTip(2, QString::fromStdString(error));
    pending_invalid_item_ = item;
    pending_invalid_prev_value_ = item->data(0, Qt::UserRole + 4).toString();
    table_->setCurrentItem(item, 2);
    QTimer::singleShot(0, this, [this, item]() {
      if (item) {
        table_->openPersistentEditor(item, 2);
        table_->setFocus();
        applyEditorErrorStyle(table_, true);
        if (auto* editor = table_->findChild<QLineEdit*>()) {
          editor->installEventFilter(this);
        }
      }
    });
    updating_ = false;
    return;
  }

  item->setData(0, Qt::UserRole + 4, item->text(2));
  item->setData(2, kInvalidRole, false);
  item->setToolTip(2, QString());
  applyEditorErrorStyle(table_, false);
  table_->closePersistentEditor(item, 2);
  if (pending_invalid_item_ == item) {
    pending_invalid_item_ = nullptr;
  }
}

void PlcMonitorWindow::onItemDoubleClicked(QTreeWidgetItem* item, int column)
{
  // BOOL/BIT (and enum) cells are now edited via the value dropdown provided by
  // the item delegate, so the old double-click toggle is no longer used.
  Q_UNUSED(item);
  Q_UNUSED(column);
}

bool PlcMonitorWindow::eventFilter(QObject* obj, QEvent* event)
{
  if (obj == table_ && pending_bool_item_) {
    if (event->type() == QEvent::KeyPress) {
      auto* keyEvent = static_cast<QKeyEvent*>(event);
      if (keyEvent->key() == Qt::Key_Return || keyEvent->key() == Qt::Key_Enter) {
        auto* item = pending_bool_item_;
        pending_bool_item_ = nullptr;

        const auto sym_index = item->data(0, Qt::UserRole).toInt();
        if (sym_index < 0) return true;

        const auto element_offset = item->data(0, Qt::UserRole + 1).toLongLong();
        const auto type = item->data(0, Qt::UserRole + 2).toString().toStdString();
        const auto is_array_elem = item->data(0, Qt::UserRole + 3).toBool();

        const auto result = tc_standard::validateInput(type, item->text(2).toStdString());
        if (!result.ok) {
          statusBar()->showMessage(QString::fromStdString(result.error));
          updating_ = true;
          item->setText(2, pending_bool_prev_value_);
          item->setBackground(2, QBrush());
          item->setToolTip(2, QString());
          updating_ = false;
          return true;
        }

        std::string error;
        if (!client_.writeValue(
              static_cast<size_t>(sym_index),
              item->text(2).toStdString(),
              error,
              is_array_elem,
              element_offset,
              type)) {
          statusBar()->showMessage(QString::fromStdString(error));
          updating_ = true;
          item->setText(2, pending_bool_prev_value_);
          updating_ = false;
        }
        item->setBackground(2, QBrush());
        item->setToolTip(2, QString());
        item->setData(0, Qt::UserRole + 4, item->text(2));
        return true;
      }

      if (keyEvent->key() == Qt::Key_Escape) {
        updating_ = true;
        pending_bool_item_->setText(2, pending_bool_prev_value_);
        pending_bool_item_->setBackground(2, QBrush());
        pending_bool_item_->setToolTip(2, QString());
        updating_ = false;
        pending_bool_item_ = nullptr;
        statusBar()->showMessage("Cancelado");
        return true;
      }
    }
  }

  if (obj == table_ && pending_invalid_item_) {
    if (event->type() == QEvent::KeyPress) {
      auto* keyEvent = static_cast<QKeyEvent*>(event);
      if (keyEvent->key() == Qt::Key_Escape) {
        revertInvalidEdit("Cancelado");
        return true;
      }
    }
  }

  if (pending_invalid_item_) {
    if (event->type() == QEvent::FocusOut && qobject_cast<QLineEdit*>(obj)) {
      revertInvalidEdit("Cancelado");
      return true;
    }
    if (obj == table_->viewport() && event->type() == QEvent::MouseButtonPress) {
      revertInvalidEdit("Cancelado");
      return false;
    }
    if (obj == table_ && event->type() == QEvent::FocusOut) {
      revertInvalidEdit("Cancelado");
      return false;
    }
  }

  return QMainWindow::eventFilter(obj, event);
}

std::string PlcMonitorWindow::groupForSymbol(const std::string& name) const
{
  // Group by the first path segment: "MAIN.axis" -> "MAIN", "SAFE.bReset" -> "SAFE".
  // Names without a leading segment fall into "Other".
  const auto dot = name.find('.');
  if (dot == std::string::npos || dot == 0) {
    return "Other";
  }
  return name.substr(0, dot);
}
