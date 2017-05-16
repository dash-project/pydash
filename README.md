# pydash

## Overview

Python bindings for DASH by exposing DASH datatypes to Python.

## Synopsis

~~~bash
$ git clone https://github.com/dash-project/pydash.git ~/tmp/pydash
$ pip install ~/tmp/pydash
$ python
>>> import pydash
>>> pydash.initialize(0, '')
>>> # See help(pydash) for API documentation
>>> pydash.finalize()
~~~

To run a pydash application on distributed nodes (via MPI), just spawn the
interpreter via `mpiexec`/`mpirun` as usual:

~~~python
# File: my_pydash_test.py
import pydash

pydash.initialize(0, "")

print("My unit id: {}".format(pydash.myid()))

pydash.finalize()
~~~

~~~bash
$ mpirun -n 4 python my_dash_test.py
~~~

## Build and Install

- Install DASH using CMake version 3.0 or newer:

    ~~~bash
    (~) $ git clone https://github.com/dash-project/dash.git -b development ./dash
    (~) $ cd dash
    (dash) $ ./build.sh && (cd build ; make doc ; make install)
    ~~~

- In PyDASH, run `build.sh`

## pybind11

- Pull from (inofficial) fork: 

      git clone https://github.com/fuchsto/pybind11.git -b embedded

- Build and install, installation path of pybind11 must be provided
  when building pydash applications

## Running Tests

- Install py.test:

    ~~~bash
    $ pip install pytest --user
    ~~~

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

<http://doc.dash-project.org/internal/PyDASH>

