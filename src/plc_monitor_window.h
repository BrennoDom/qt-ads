// ADS Qt Monitor — live TwinCAT PLC variable monitor over ADS for Linux.
//
// Copyright (c) 2026 Brenno Domingues <brennohdomingues@gmail.com>
// GitHub: https://github.com/BrennoDom
//
// SPDX-License-Identifier: MIT
// Licensed under the MIT License; see the LICENSE file in the project root.

#pragma once

#include <QMainWindow>
#include <QTreeWidget>
#include <QTimer>
#include <QPushButton>
#include <unordered_map>

#include "plc_client.h"
#include "bhf_struct_tree.h"

class PlcMonitorWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit PlcMonitorWindow(QWidget* parent = nullptr);

private slots:
  void refreshValues();
  void initialLoadTypes();
  void deferredLoad();
  void onItemChanged(QTreeWidgetItem* item, int column);
  void onItemDoubleClicked(QTreeWidgetItem* item, int column);
  void onSetRun();
  void onSetConfig();
  void tryReconnectAfterRun();

private:
  bool eventFilter(QObject* obj, QEvent* event) override;
  void setupTable();
  void updateTable(const std::vector<std::string>& values);
  bool ensureTransportConnected();
  bool ensureConnected();
  void revertInvalidEdit(const QString& message);
  void suspendPolling(const QString& message);
  void resumePolling();
  bool isTargetPortMissing(const std::string& message) const;
  std::string groupForSymbol(const std::string& name) const;
  bool parseArrayBounds(const std::string& type, long long& lower, long long& upper) const;
  bool hasParentSymbol(const std::string& name) const;
  bool addSymbolChildren(const std::vector<SymbolEntry>& syms, int parent_index, QTreeWidgetItem* parent);

  QTreeWidget* table_;
  QTimer* timer_;
  QPushButton* run_button_;
  QPushButton* config_button_;
  PlcClient client_;
  AmsNetId netid_;
  std::string ip_;
  uint16_t ams_port_;
  std::vector<QTreeWidgetItem*> value_items_;
  std::vector<std::vector<QTreeWidgetItem*>> array_children_items_;
  bool updating_;
  QTreeWidgetItem* pending_bool_item_;
  QString pending_bool_prev_value_;
  QTreeWidgetItem* pending_invalid_item_;
  QString pending_invalid_prev_value_;
  bool polling_suspended_;
  int run_reconnect_attempts_;
  std::vector<std::vector<uint8_t>> last_raw_values_;
  std::unordered_map<std::string, int> symbol_index_by_name_;
  StructTree struct_tree_;
};
