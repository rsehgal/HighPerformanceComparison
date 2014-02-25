# - Finds Vc installation ( the wrapper library to SIMD intrinsics )
# This module sets up Vc information 
# It defines:
# OpenCL_FOUND          If the ROOT is found
# OpenCL_INCLUDE_DIR    PATH to the include directory
# OpenCL_LIBRARIES      Most common libraries
# OpenCL_LIBRARY_DIR    PATH to the library directory 

# look if an environment variable NT2ROOT exists
set(OpenCLROOT $ENV{OpenCLROOT})

find_library(OpenCL_LIBRARIES liboclUtil_x86_64.a PATHS ${OpenCLROOT}/lib)
if (OpenCL_LIBRARIES) 
   set(OpenCL_FOUND TRUE)	
   #string(REPLACE "/lib/libwt.so" "" NT2ROOT  ${NT2_LIBRARIES})
   set(OpenCL_INCLUDE_DIR ${OpenCLROOT}/inc)
   set(OpenCL_LIBRARY_DIR ${OpenCLROOT}/lib)
   message(STATUS "Found OpenCL library in ${OpenCL_LIBRARIES}")		
else()
   message(STATUS "OpenCL library not found; try to set a OpenCLROOT environment variable to the base installation path or add -DOpenCLROOT= to the cmake command")	
endif()



