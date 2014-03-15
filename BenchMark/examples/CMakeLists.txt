cmake_minimum_required(VERSION 2.8)
set(OUTDIR ${PROJECT_SOURCE_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTDIR}/bin)

#set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} /home/ramanNew/cmake/modules)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake/modules) 

find_package(BLAS REQUIRED)
include_directories(${BLAS_INCLUDE_DIR})

find_package(Blaze REQUIRED)
include_directories(${Blaze_INCLUDE_DIR})

find_package(TBB)
include_directories(${TBB_INCLUDE_DIR})

find_package(Vc REQUIRED)
include_directories(${VC_INCLUDE_DIR})

find_package(BOOST REQUIRED)
include_directories(${BOOST_INCLUDE_DIR})

include_directories(inc)


#Add list of file that needs to be compiled.
#file(GLOB testsources tests/denseVectorAddition.cpp tests/heapTestVectorAddition.cpp  tests/heapTestMatrixVector.cpp tests/matrixVector.cpp tests/daxpy.cpp tests/heapTestDaxpy.cpp)
file(GLOB testsources tests/heapTestMatrixVector.cpp)
if( USEAVX )
    set_source_files_properties(${testsources} PROPERTIES COMPILE_FLAGS "-O2 -fpermissive -mavx -fabi-version=0")
    add_definitions( "-DUSEAV" )
else()
    set_source_files_properties(${testsources} PROPERTIES COMPILE_FLAGS "-O2 -fpermissive -msse4.1")
endif( USEAVX )


foreach( test ${testsources} )
        get_filename_component( TESTEXEC ${test} NAME_WE)
        add_executable(${TESTEXEC} ${test} src/Vector3DFast.cpp)
        target_link_libraries(${TESTEXEC} "-I /home/raman/BOOST/boost_1_55_0/BUILD/include -L ${Blaze_LIBRARY_DIR} -L ${TBB_LIBRARIES} -L ${VC_LIBRARY_DIR} -L ${BLAS_LIBRARY_DIR} ${BLAS_LIBRARIES} -lVc -lblaze -lrt -lpthread")
endforeach( test )


