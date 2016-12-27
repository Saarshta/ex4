cmake_minimum_required(VERSION 3.6)
project(ex4)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
add_subdirectory(lib/googletest-master)

include_directories(lib/googletest-master/googletest/include)

set(SOURCE_FILES main.cpp test/NodeTest.cpp test/DriverTest.cpp test/MatrixTest.cpp src/AbstractNode.cpp src/AbstractNode.h src/Bfs.cpp src/Bfs.h src/Matrix.cpp src/Matrix.h src/MatrixNode.cpp src/MatrixNode.h src/Point.cpp src/Point.h src/Defines.h test/TripTest.cpp src/Driver.cpp src/Driver.h src/Cab.cpp src/Cab.h src/Map.cpp src/Map.h src/Passenger.cpp src/Passenger.h src/TaxiCenter.cpp src/TaxiCenter.h src/LuxuryCab.cpp src/LuxuryCab.h src/StandardCab.cpp src/StandardCab.h src/Color.h src/Manufacturer.h src/Status.h src/Trip.cpp src/Trip.h test/CabTest.cpp test/TaxiCenterTest.cpp src/MainFlow.cpp src/MainFlow.h src/SearchAlgorithm.h src/AbstractPoint.cpp src/AbstractPoint.h src/MapRestartListener.cpp src/MapRestartListener.h src/SearchAlgorithm.cpp test/MapRestartListenerTest.cpp)
add_executable(ex4 ${SOURCE_FILES} test/NodeTest.cpp test/DriverTest.cpp src/Defines.h test/MatrixTest.cpp test/TripTest.cpp src/Driver.cpp src/Driver.h src/Cab.cpp src/Cab.h src/Map.cpp src/Map.h src/Passenger.cpp src/Passenger.h src/TaxiCenter.cpp src/TaxiCenter.h src/LuxuryCab.cpp src/LuxuryCab.h src/StandardCab.cpp src/StandardCab.h src/Color.h src/Manufacturer.h src/Status.h src/Trip.cpp src/Trip.h test/CabTest.cpp test/TaxiCenterTest.cpp src/MainFlow.cpp src/MainFlow.h src/SearchAlgorithm.h src/AbstractPoint.cpp src/AbstractPoint.h test/MapRestartListenerTest.cpp)
target_link_libraries(ex4 gtest gtest_main)