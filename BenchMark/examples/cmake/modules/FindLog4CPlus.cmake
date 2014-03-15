# - Finds Vc installation ( the wrapper library to SIMD intrinsics )
# This module sets up Vc information 
# It defines:
# Log4CPlus_FOUND          If the ROOT is found
# Log4CPlus_INCLUDE_DIR    PATH to the include directory
# Log4CPlus_LIBRARIES      Most common libraries
# Log4CPlus_LIBRARY_DIR    PATH to the library directory 

# look if an environment variable Log4CPlusROOT exists
set(Log4CPlusROOT $ENV{Log4CPlusROOT})

find_library(Log4CPlus_LIBRARIES liblog4cplus.so PATHS ${Log4CPlusROOT}/lib)
if (Log4CPlus_LIBRARIES) 
   set(Log4CPlus_FOUND TRUE)	
   #string(REPLACE "/lib/libnt2.a" "" Log4CPlusROOT  ${Log4CPlus_LIBRARIES})
   set(Log4CPlus_INCLUDE_DIR ${Log4CPlusROOT}/include)
   set(Log4CPlus_LIBRARY_DIR ${Log4CPlusROOT}/lib)
   message(STATUS "Found Log4CPlus library in ${Log4CPlus_LIBRARIES}")		
else()
   message(STATUS "Log4CPlus library not found; try to set a Log4CPlusROOT environment variable to the base installation path or add -DLog4CPlusROOT= to the cmake command")	
endif()



