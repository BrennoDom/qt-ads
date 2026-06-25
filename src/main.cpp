// ADS Qt Monitor — live TwinCAT PLC variable monitor over ADS for Linux.
//
// Copyright (c) 2026 Brenno Domingues <brennohdomingues@gmail.com>
// GitHub: https://github.com/BrennoDom
//
// SPDX-License-Identifier: MIT
// Licensed under the MIT License; see the LICENSE file in the project root.

#include <QApplication>

#include "plc_monitor_window.h"

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  PlcMonitorWindow window;
  window.resize(900, 600);
  window.show();
  return app.exec();
}
