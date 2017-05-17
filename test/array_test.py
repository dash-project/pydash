import pydash

pydash.initialize(0, "")

myid   = pydash.myid().id()
nunits = pydash.nunits()
# Collectively instantiate array:
array  = pydash.ArrayInt(3 * nunits)
# Initialize array:
array.set(myid * 3 + 0, 100 * (1 + myid) + 0)
array.set(myid * 3 + 1, 100 * (1 + myid) + 1)
array.set(myid * 3 + 2, 100 * (1 + myid) + 2)
# Wait for all units:
pydash.barrier()
# Read array elements from remote unit:
fromid = nunits - myid - 1

print("Unit {0:2} read array[{1:3} ..{2:3}]:"
        .format(myid, fromid * 3, fromid * 3 + 2),
      repr(array.get(fromid * 3 + 0)).rjust(4),
      repr(array.get(fromid * 3 + 1)).rjust(4),
      repr(array.get(fromid * 3 + 2)).rjust(4))

pydash.finalize()
