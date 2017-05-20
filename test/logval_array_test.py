import pydash

pydash.initialize(0, "")

myid   = pydash.myid().id()
nunits = pydash.nunits()
# Collectively instantiate array:
array  = pydash.ArrayLV(3 * nunits)
# Initialize array:
array[myid * 3 + 0] = { "first",  myid };
array[myid * 3 + 1] = { "second", myid };
array[myid * 3 + 2] = { "third",  myid };
# Wait for all units:
pydash.barrier()
# Read array elements from remote unit:
fromid = nunits - myid - 1

if myid % 2 == 1:
    myval = array[fromid * 3 + 1]

pydash.finalize()
