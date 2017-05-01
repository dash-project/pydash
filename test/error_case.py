import gc
import error_class

ec = error_class(42)
print ec.f() #should print out 'KABOOM'
gc.collect()
