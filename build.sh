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

# Configure with default release build settings:
mkdir -p $BUILD_DIR
rm -Rf $BUILD_DIR/*
(cd $BUILD_DIR && cmake -DCMAKE_BUILD_TYPE=Release \
                        -DINSTALL_PREFIX=$HOME/opt/pydash-0.1.0/ \
                        \
                        -DENABLE_LOGGING=OFF \
                        -DENABLE_TRACE_LOGGING=OFF \
                        \
                        -DBUILD_EXAMPLES=ON \
                        -DBUILD_TESTS=ON \
                        \
                        -DCMAKE_EXPORT_COMPILE_COMMANDS=ON \
                        ../ && \
 await_confirm && \
 make -j 4 VERBOSE=1) && (cp $BUILD_DIR/compile_commands.json .) && \
exit_message

