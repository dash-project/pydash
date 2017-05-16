# pydash

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
My unit id: 2
My unit id: 1
My unit id: 3
My unit id: 0
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

- Pull from official pybind11 repository: 

      git clone https://github.com/pybind/pybind11

- Build and install, installation path of pybind11 must be provided
  when building pydash applications via CMake option `PYBIND11_BASE`

## Running Tests

- Install py.test:

    ~~~bash
    $ pip install pytest --user
    ~~~


# Further References

## Extending Python with C or C++ using Python API 

See this reference as a starting point:

- <https://docs.python.org/3.7/extending/extending.html#>

## Links

- <https://www.python.org/dev/peps/pep-0489/>
- <https://packaging.python.org/extensions/>
- <http://doc.dash-project.org/internal/PyDASH>

