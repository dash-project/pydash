import pydash

pydash.initialize(0, "")

myid   = pydash.myid().id()
nunits = pydash.nunits()

# Collectively instantiate array:
array  = pydash.ArrayLV(3 * nunits)

# Initialize array:
array[myid * 3 + 0] = pydash.LV(myid, "first")
array[myid * 3 + 1] = pydash.LV(myid, "second")
array[myid * 3 + 2] = pydash.LV(myid, "third")

# Wait for all units:
pydash.barrier()

# Read array elements from remote unit:
fromid = nunits - myid - 1

if myid % 2 == 1:
    myval = array[fromid * 3 + 1]

pydash.finalize()
