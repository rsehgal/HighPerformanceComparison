# - Finds Vc installation ( the wrapper library to SIMD intrinsics )
# This module sets up Vc information 
# It defines:
# BOOST_FOUND          If the ROOT is found
# BOOST_INCLUDE_DIR    PATH to the include directory
# BOOST_LIBRARIES      Most common libraries
# BOOST_LIBRARY_DIR    PATH to the library directory 

# look if an environment variable BOOSTROOT exists
set(BOOSTROOT $ENV{BOOSTROOT})

find_library(BOOST_LIBRARIES libboost_atomic.a PATHS ${BOOSTROOT}/lib)
if (BOOST_LIBRARIES) 
   set(BOOST_FOUND TRUE)	
   #string(REPLACE "/lib/libboost_atomic.a" "" BOOSTROOT  ${BOOST_LIBRARIES})
   set(BOOST_INCLUDE_DIR ${BOOSTROOT}/include)
   set(BOOST_LIBRARY_DIR ${BOOSTROOT}/lib)
   message(STATUS "Found BOOST library in ${BOOST_LIBRARIES}")		
else()
   message(STATUS "BOOST library not found; try to set a BOOSTROOT environment variable to the base installation path or add -DBOOSTROOT= to the cmake command")	
endif()



