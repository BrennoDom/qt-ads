# ADS Qt GUI Monitor

Standalone Qt GUI project that communicates with Beckhoff ADS.

This repository keeps the GUI code here and includes the Beckhoff ADS library as a Git submodule in `ADS/`.

## Clone

```bash
git clone https://github.com/BrennoDom/ads-qt-linux.git
cd ads-qt-gui
git submodule update --init --recursive
```

## Build GUI

```bash
cmake -S . -B build
cmake --build build
./build/ads_qt_monitor
```

## Notes

- `CMakeLists.txt` builds the `ADS` submodule and links against target `ads`.
- Qt 6 Widgets is required.
