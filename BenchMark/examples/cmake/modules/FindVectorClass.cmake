# - Finds Vc installation ( the wrapper library to SIMD intrinsics )
# This module sets up Vc information 
# It defines:
# VC_FOUND          If the ROOT is found
# VC_INCLUDE_DIR    PATH to the include directory
# VC_LIBRARIES      Most common libraries
# VC_LIBRARY_DIR    PATH to the library directory 

# look if an environment variable VCROOT exists
set(VectorClassROOT $ENV{VectorClassROOT})

find_library(VectorClass_LIBRARIES libVectorClass.a PATHS ${VectorClassROOT})
if (VectorClass_LIBRARIES) 
   set(VectorClass_FOUND TRUE)	
   #string(REPLACE "/lib/libVc.a" "" VCROOT  ${VC_LIBRARIES})
   set(VectorClass_INCLUDE_DIR ${VectorClassROOT})
   #set(VC_LIBRARY_DIR ${VCROOT}/lib)
   message(STATUS "Found VectorClass library in ${VectorClass_LIBRARIES}")		
else()
   message(STATUS "VectorClass library not found; try to set a VecROOT environment variable to the base installation path or add -DVCROOT= to the cmake command")	
endif()



