# - Finds Vc installation ( the wrapper library to SIMD intrinsics )
# This module sets up Vc information 
# It defines:
# WT_FOUND          If the ROOT is found
# WT_INCLUDE_DIR    PATH to the include directory
# WT_LIBRARIES      Most common libraries
# WT_LIBRARY_DIR    PATH to the library directory 

# look if an environment variable NT2ROOT exists
set(WTROOT $ENV{WTROOT})

find_library(WT_LIBRARIES libwt.so PATHS ${WTROOT}/lib)
if (WT_LIBRARIES) 
   set(WT_FOUND TRUE)	
   #string(REPLACE "/lib/libwt.so" "" NT2ROOT  ${NT2_LIBRARIES})
   set(WT_INCLUDE_DIR ${WTROOT}/include)
   set(WT_LIBRARY_DIR ${WTROOT}/lib)
   message(STATUS "Found WT library in ${WT_LIBRARIES}")		
else()
   message(STATUS "WT library not found; try to set a WTROOT environment variable to the base installation path or add -DWTROOT= to the cmake command")	
endif()



