# - Finds Vc installation ( the wrapper library to SIMD intrinsics )
# This module sets up Vc information 
# It defines:
# NT2_FOUND          If the ROOT is found
# NT2_INCLUDE_DIR    PATH to the include directory
# NT2_LIBRARIES      Most common libraries
# NT2_LIBRARY_DIR    PATH to the library directory 

# look if an environment variable NT2ROOT exists
set(NT2ROOT $ENV{NT2ROOT})

find_library(NT2_LIBRARIES libnt2.a PATHS ${NT2ROOT}/lib)
if (NT2_LIBRARIES) 
   set(NT2_FOUND TRUE)	
   string(REPLACE "/lib/libnt2.a" "" NT2ROOT  ${NT2_LIBRARIES})
   set(NT2_INCLUDE_DIR ${NT2ROOT}/include)
   set(NT2_LIBRARY_DIR ${NT2ROOT}/lib)
   message(STATUS "Found NT2 library in ${NT2_LIBRARIES}")		
else()
   message(STATUS "NT2 library not found; try to set a NT2ROOT environment variable to the base installation path or add -DNT2ROOT= to the cmake command")	
endif()



