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

# Set minimum to be found:
if (myid == 0):
    print("Array size: {}".format(array.size()))
    array[2] = 12

# Wait for all units:
pydash.barrier()

min_val = array.min(-1)
min_idx = array.argmin()

print("Unit {}: got minimum element {} at index {}"
        .format(myid, min_val, min_idx))

pydash.finalize()
