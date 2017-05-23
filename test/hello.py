import pydash

pydash.initialize(0,"")

myid = pydash.myid().id()
nunits = pydash.nunits()

print("Hello World! My unit id:" + str(myid) + " team size:" + str(nunits)) 

pydash.finalize()
