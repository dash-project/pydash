#!/bin/sh

DASH_BASE=$HOME/opt/dash-0.3.0-dev
PYBIND11_BASE=$HOME/opt/pybind11embedded

c++ -O3 -std=c++11 \
  -I$DASH_BASE/include \
  -I$PYBIND11_BASE/include \
  -L$DASH_BASE/lib \
  $(python-config --cflags) \
  -static -fPIC \
  -ldart-base \
  -ldart-mpi \
  -ldash-mpi \
  -c Init_h_binding.cpp \
  -o Init.o


c++ -O3 -std=c++11 \
  -I$DASH_BASE/include \
  -I$PYBIND11_BASE/include \
  -L$DASH_BASE/lib \
  -static -fPIC \
  -ldart-base \
  -ldart-mpi \
  -ldash-mpi \
  $(python-config --cflags) \
  $(python-config --ldflags) \
  -shared -fPIC \
  Init.o \
  -o dash.so

