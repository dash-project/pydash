# starte mit mpirun -n 3 python3.5m test_2.py

import pydash
import time
import gc


pydash.initialize(0, "")

myid   = pydash.myid().id()
nunits = pydash.nunits()

# Collectively instantiate array:
array  = pydash.ArrayLV(3 * nunits)

# Initialize array:
array[0] = pydash.LV(myid, "first");
array[1] = pydash.LV(myid, "second");
array[2] = pydash.LV(myid, "third");

# Wait for all units:
pydash.barrier()

if myid == 0:
    gc.collect()

if myid == 1:
    time.sleep(10)
    gc.collect()

if myid == 2:
    time.sleep(10)
    gc.collect()

pydash.finalize()
