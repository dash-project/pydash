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

## Basic Examples

### Hello World

To run a pydash application on distributed nodes (via MPI), just spawn the
interpreter via `mpiexec`/`mpirun` as usual:

~~~python
# File: initialize_test.py
import pydash

pydash.initialize(0, "")

print "My unit id: {}".format(pydash.myid().id())

pydash.finalize()
~~~

~~~
$ mpirun -n 4 python initialize_test.py
My unit id: 2
My unit id: 1
My unit id: 3
My unit id: 0
~~~

### Array Read/Write

~~~python
# File: array_test.py
import pydash

pydash.initialize(0, "")

myid   = pydash.myid().id()
nunits = pydash.nunits()
# Collectively instantiate array:
array  = pydash.ArrayInt(3 * nunits)
# Initialize array:
array[myid * 3 + 0] = 100 * (1 + myid) + 0
array[myid * 3 + 1] = 100 * (1 + myid) + 1
array[myid * 3 + 2] = 100 * (1 + myid) + 2
# Wait for all units:
pydash.barrier()
# Read array elements from remote unit:
fromid = nunits - myid - 1
# Print remote values:
print("Unit {0:2} read array[{1:3} ..{2:3}]:"
        .format(myid, fromid * 3, fromid * 3 + 2),
      "  u:", repr(array.unit_at(fromid * 3 + 0)).rjust(2), repr(array[fromid * 3 + 0]).rjust(5),
      "  u:", repr(array.unit_at(fromid * 3 + 1)).rjust(2), repr(array[fromid * 3 + 1]).rjust(5),
      "  u:", repr(array.unit_at(fromid * 3 + 2)).rjust(2), repr(array[fromid * 3 + 2]).rjust(5))

pydash.finalize()
~~~

~~~
$ mpirun -n 5 python array_test.py
Unit  0 read array[ 12 .. 14]:   u:  4   500   u:  4   501   u:  4   502
Unit  3 read array[  3 ..  5]:   u:  1   200   u:  1   201   u:  1   202
Unit  2 read array[  6 ..  8]:   u:  2   300   u:  2   301   u:  2   302
Unit  4 read array[  0 ..  2]:   u:  0   100   u:  0   101   u:  0   102
Unit  1 read array[  9 .. 11]:   u:  3   400   u:  3   401   u:  3   402
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

## pybind11 User Guides

- <https://dmtn-026.lsst.io/> (outdated)
- <https://developer.lsst.io/coding/python_wrappers_for_cpp_with_pybind11.html>

## Extending Python with C or C++ using Python API 

See this reference as a starting point:

- <https://docs.python.org/3.7/extending/extending.html#>

## Links

- <https://www.python.org/dev/peps/pep-0489/>
- <https://packaging.python.org/extensions/>
- <http://doc.dash-project.org/internal/PyDASH>

