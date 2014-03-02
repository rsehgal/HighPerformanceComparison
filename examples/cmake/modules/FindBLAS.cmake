# - Finds Vc installation ( the wrapper library to SIMD intrinsics )
# This module sets up Vc information 
# It defines:
# BLAS_FOUND          If the ROOT is found
# BLAS_INCLUDE_DIR    PATH to the include directory
# BLAS_LIBRARIES      Most common libraries
# BLAS_LIBRARY_DIR    PATH to the library directory 

# look if an environment variable BLASROOT exists
set(BLASROOT $ENV{BLASROOT})

find_library(BLAS_LIBRARIES libgoto2.a PATHS ${BLASROOT})
if (BLAS_LIBRARIES) 
   set(BLAS_FOUND TRUE)	
   #string(REPLACE "/lib/libnt2.a" "" BLASROOT  ${BLAS_LIBRARIES})
   set(BLAS_INCLUDE_DIR ${BLASROOT})
   set(BLAS_LIBRARY_DIR ${BLASROOT})
   message(STATUS "Found BLAS library in ${BLAS_LIBRARIES}")		
else()
   message(STATUS "BLAS library not found; try to set a BLASROOT environment variable to the base installation path or add -DBLASROOT= to the cmake command")	
endif()



