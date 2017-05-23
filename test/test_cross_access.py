# starte mit mpirun -n 2 python3.5m test_4.py

import pydash
import time
import gc


pydash.initialize(0, "")

myid   = pydash.myid().id()
nunits = pydash.nunits()

# Collectively instantiate array:
array  = pydash.ArrayLV(2)


if myid == 0:
    array[0] = pydash.LV(myid, "zero");

if myid == 1:
    array[1] = pydash.LV(myid, "first");


pydash.barrier()

if myid == 0:
    print(array[1].value())

if myid == 1:
    print(array[0].value())

pydash.finalize()
