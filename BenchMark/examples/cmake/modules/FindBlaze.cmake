# - Finds Vc installation ( the wrapper library to SIMD intrinsics )
# This module sets up Vc information 
# It defines:
# Blaze_FOUND          If the ROOT is found
# Blaze_INCLUDE_DIR    PATH to the include directory
# Blaze_LIBRARIES      Most common libraries
# Blaze_LIBRARY_DIR    PATH to the library directory 

# look if an environment variable BlazeROOT exists
set(BlazeROOT $ENV{BlazeROOT})

find_library(Blaze_LIBRARIES libblaze.so PATHS ${BlazeROOT}/lib)
if (Blaze_LIBRARIES) 
   set(Blaze_FOUND TRUE)	
   #string(REPLACE "/lib/libnt2.a" "" BlazeROOT  ${Blaze_LIBRARIES})
   set(Blaze_INCLUDE_DIR ${BlazeROOT}/include)
   set(Blaze_LIBRARY_DIR ${BlazeROOT}/lib)
   message(STATUS "Found Blaze library in ${Blaze_LIBRARIES}")		
else()
   message(STATUS "Blaze library not found; try to set a BlazeROOT environment variable to the base installation path or add -DBlazeROOT= to the cmake command")	
endif()



