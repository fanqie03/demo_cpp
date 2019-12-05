

from distutils.core import setup 
from distutils.extension import Extension 
  
setup(name="PackageName", 
 ext_modules=[ 
  Extension("test2", ["test2.cpp"], 
  libraries = ["boost_python"]) 
 ])