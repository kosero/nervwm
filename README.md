# KIRANWM [![Licence](https://img.shields.io/badge/License-BSD-red.svg)](LICENSE)

## About

KIRANWM is a hobby window manager written in C. It is only for learning what is happening in the background.

### Required

- wlroots-0.19
- wayland-server
- libdrm
- pixman
- pkg-config
- gcc or clang
- make (if using Makefile)
- cmake (if using CMake)

### Optional / Recommended

- mesa or GPU drivers
- libxkbcommon
- libsystemd
- libwayland-client

### Build

```
$ git clone https://github.com/kosero/kiranwm.git && cd kiranwm
$ mkdir build
$ cd build
$ cmake ..
$ make
```
