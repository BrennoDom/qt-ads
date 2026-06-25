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
