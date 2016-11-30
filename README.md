# pydash

## Overview

Python bindings for DASH by exposing DASH datatypes to Python.
Soon, you will be able to do all your fancy Python things with the power
of DASH. 

## Build and Install

- Install DASH using CMake version 3.0 or newer:

    ~~~bash
    (~) $ git clone https://github.com/dash-project/dash.git -b development ./dash
    (~) $ cd dash
    (dash) $ ./build.sh && (cd build ; make doc ; make install)
    ~~~

- In PyDASH, run `build.sh`

## Extending Python with C or C++ using Python API 

See this reference as a starting point

<https://docs.python.org/3.7/extending/extending.html#>


## Quick Start to  Python  Modules

The file `/Python-3.X.X/Modules/xxmodule.c` includes a template for C
bindings and might be used as a reference for quick starters.

It can be found  here: <https://www.python.org/downloads/release/python-360b1/>


## Links

<https://www.python.org/dev/peps/pep-0489/>


<https://packaging.python.org/extensions/>
