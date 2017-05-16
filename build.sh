#!/bin/sh

BUILD_DIR=./build


FORCE_BUILD=false
if [ "$1" = "-f" ]; then
  FORCE_BUILD=true
fi

await_confirm() {
  if ! $FORCE_BUILD; then
    echo ""
    echo "   To build using these settings, hit ENTER"
    read confirm
  fi
}

exit_message() {
  echo "-------------------------------------------------------------"
  echo "Done. To install PyDASH, run    make install    in $BUILD_DIR"
}

if [ "${PYCXX_BASE}" = "" ] ; then
  PYCXX_BASE=${HOME}/opt/pycxx
fi

if [ "${PYBIND11_BASE}" = "" ] ; then
  PYBIND11_BASE="/opt/pybind11"
fi

if [ "${DASH_BASE}" = "" ] ; then
  DASH_BASE="/opt/dash/dash-0.3.0"
fi

# Configure with default release build settings:
mkdir -p $BUILD_DIR
rm -Rf $BUILD_DIR/*
(cd $BUILD_DIR && cmake -DCMAKE_BUILD_TYPE=Release \
                        -DINSTALL_PREFIX=./pydash-0.1.0/ \
                        \
                        -DENABLE_LOGGING=OFF \
                        -DENABLE_TRACE_LOGGING=OFF \
                        \
                        -DBUILD_EXAMPLES=ON \
                        -DBUILD_TESTS=ON \
                        \
                        -DDASH_BASE=$DASH_BASE \
                        -DPYBIND11_BASE=$PYBIND11_BASE \
                        \
                        -DCMAKE_EXPORT_COMPILE_COMMANDS=ON \
                        ../ && \
 await_confirm && \
 make -j 4 VERBOSE=1) && (cp $BUILD_DIR/compile_commands.json .) && \
exit_message

