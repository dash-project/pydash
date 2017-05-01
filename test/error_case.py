import gc
import error_class

ec = error_class()
print ec.f() #should print out 'KABOOM'
gc.collect()