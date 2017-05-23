import pydash
import time

pydash.initialize(0, "")

myid   = pydash.myid().id()
nunits = pydash.nunits()

# Collectively instantiate array:
array  = pydash.ArrayLV(3 * nunits)


if myid == 0:
    time.sleep(20)
    array[myid * 3 + 0] = pydash.LV(myid, "first")


if myid == 1:
    time.sleep(10)
    array[myid * 3 + 1] = pydash.LV(myid, "second")

if myid == 2:
    time.sleep(0)
    array[myid * 3 + 2] = pydash.LV(myid, "third")

# Wait for all units:
pydash.barrier()

# Read array elements from remote unit:
fromid = nunits - myid - 1

if myid % 2 == 1:
    myval = array[fromid * 3 + 1]

pydash.finalize()

