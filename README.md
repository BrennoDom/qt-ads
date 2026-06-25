# ADS Qt GUI Monitor

Standalone Qt GUI project that communicates with Beckhoff ADS.

Project layout:

- `src/` — the GUI/application source (`.cpp`/`.h`).
- `include/ADS/` — the Beckhoff ADS library, a Git submodule.
- `include/twincat_ads/` — TwinCAT ADS headers and the platform library (`linux/`, `win/`).

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

- `CMakeLists.txt` builds the `include/ADS` submodule and links against target `ads`.
- Qt 6 Widgets is required.
