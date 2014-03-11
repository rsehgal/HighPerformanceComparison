cmake_minimum_required(VERSION 2.8)
set(OUTDIR ${PROJECT_SOURCE_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${MYLIBROOT}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTDIR}/lib)
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
#file(GLOB testsources tests/ex1.cpp) # tests/ex3Simple.cpp)
#file(GLOB testsources tests/denseVectorAddition.cpp tests/daxpy.cpp tests/matrixVector.cpp)
#file(GLOB testsources  tests/matrixSimple2.cpp tests/matrixSimple3.cpp)
#file(GLOB testsources tests/matrixVector.cpp)
#file(GLOB testsources tests/matrixVectorDemo.cpp)
file(GLOB testsources tests/heapTestMatrixVector.cpp) # tests/matrixVector.cpp)
#file(GLOB testsources tests/vector3DFastDemo.cpp) # tests/randtest.cpp)
#file(GLOB testsources tests/denseVectorAddition.cpp tests/heapTest.cpp)
#file(GLOB testsources tests/*.cpp)
if( USEAVX )
    set_source_files_properties(${testsources} PROPERTIES COMPILE_FLAGS "-O2 -fpermissive -mavx -fabi-version=0")
    add_definitions( "-DUSEAV" )
else()
    set_source_files_properties(${testsources} PROPERTIES COMPILE_FLAGS "-O2 -fpermissive -msse4.1")
endif( USEAVX )

#file(GLOB testsources tests/*.cpp)
#set_source_files_properties(${testsources} PROPERTIES COMPILE_FLAGS "-O2 -S")

foreach( test ${testsources} )
        get_filename_component( TESTEXEC ${test} NAME_WE)
        add_executable(${TESTEXEC} ${test} src/Vector3DFast.cpp)
        target_link_libraries(${TESTEXEC} "-I /home/raman/BOOST/boost_1_55_0/BUILD/include -L ${Blaze_LIBRARY_DIR} -L ${TBB_LIBRARIES} -L ${VC_LIBRARY_DIR} -L ${BLAS_LIBRARY_DIR} -lgoto2_nehalemp-r3.14 -lVc -lblaze -lrt -lpthread")
endforeach( test )


