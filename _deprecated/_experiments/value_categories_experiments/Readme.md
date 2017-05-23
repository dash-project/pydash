## Build on macOS using
~~~(Shell)
c++ -O3 -shared -std=c++11 -I ~/workspaces/pybind11/include `python-config --cflags --ldflags` array_wrapper_binding.cpp array_maker.o -o ArrayWrapper.so
~~~