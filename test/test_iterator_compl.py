import pydash

pydash.initialize(0, "") 
myid = pydash.myid().id() 
nunits = pydash.nunits()

# Collectively instantiate 
array = pydash.ArrayInt(3 * nunits) 

# Initialize array: 
array[myid * 3 + 0] = 100 * (1 + myid) + 0
array[myid * 3 + 1] = 100 * (1 + myid) + 1
array[myid * 3 + 2] = 100 * (1 + myid) + 2

#Wait for all units:
pydash.barrier()

#Unit 0 prints out values of array
if myid == 0:
  for val in array: 
    print(val.get())

pydash.barrier()

#Unit 0 sets all values of array to 99
if myid == 0:
  for val in array: 
    val.set(99)


pydash.barrier()

#Unit 0 prints out values of array
if myid == 0:
  for val in array:
    print(val.get())


pydash.finalize()
