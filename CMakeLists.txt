cmake_minimum_required(VERSION 3.7)

project(OptimalDrone)

set(INCLUDE_DIRECTORY inc)
set(SOURCE_DIRECTORY src)
set(RESOURCE_DIRECTORY res)
set(TEST_DIRECTORY test)

include_directories( ${INCLUDE_DIRECTORY} )


#copy res to build directory
if(WIN32 AND Release)
	FILE(COPY ${RESOURCE_DIRECTORY} DESTINATION "${CMAKE_BINARY_DIR}/Release")
elseif(WIN32)#debug version
	FILE(COPY ${RESOURCE_DIRECTORY} DESTINATION "${CMAKE_BINARY_DIR}/Debug")
else(WIN32 AND Release)#not windows
	FILE(COPY ${RESOURCE_DIRECTORY} DESTINATION "${CMAKE_BINARY_DIR}")
endif(WIN32 AND Release)


#drone sources
set(DRONE_SOURCES
	${SOURCE_DIRECTORY}/Part/PartInterface.cpp
	${SOURCE_DIRECTORY}/Part/Battery.cpp
	${SOURCE_DIRECTORY}/Part/ElectronicSpeedController.cpp
	${SOURCE_DIRECTORY}/Part/FlightController.cpp
	${SOURCE_DIRECTORY}/Part/Frame.cpp
	${SOURCE_DIRECTORY}/Part/Kit.cpp
	${SOURCE_DIRECTORY}/Part/Motor.cpp
	${SOURCE_DIRECTORY}/Part/PowerDistributionBoard.cpp
	${SOURCE_DIRECTORY}/Part/Propeller.cpp
	${SOURCE_DIRECTORY}/Drone.cpp
)

set(DRONE_INCLUDES
	${INCLUDE_DIRECTORY}/Part/PartInterface.hpp
	${INCLUDE_DIRECTORY}/Part/PartTypes.h
	${INCLUDE_DIRECTORY}/Part/Battery.hpp
	${INCLUDE_DIRECTORY}/Part/ElectronicSpeedController.hpp
	${INCLUDE_DIRECTORY}/Part/FlightController.hpp
	${INCLUDE_DIRECTORY}/Part/Kit.hpp
	${INCLUDE_DIRECTORY}/Part/Frame.hpp
	${INCLUDE_DIRECTORY}/Part/Motor.hpp
	${INCLUDE_DIRECTORY}/Part/PowerDistributionBoard.hpp
	${INCLUDE_DIRECTORY}/Part/Propeller.hpp
	${INCLUDE_DIRECTORY}/Drone.hpp
)

add_library( Drone
	${DRONE_SOURCES}
	${DRONE_INCLUDES}
)


#permutation and backtracking
set( DRONEOPTIMIZE_SOURCES
	${SOURCE_DIRECTORY}/GeneratePermutations.cpp
	${SOURCE_DIRECTORY}/AnalyzePermutation.cpp
	${SOURCE_DIRECTORY}/DefaultConfig.cpp
	${SOURCE_DIRECTORY}/Metric/MetricInterface.cpp
	${SOURCE_DIRECTORY}/Metric/TotalMass.cpp
)

set( DRONEOPTIMIZE_INCLUDES
	${INCLUDE_DIRECTORY}/GeneratePermutations.hpp
	${INCLUDE_DIRECTORY}/AnalyzePermutation.hpp
	${INCLUDE_DIRECTORY}/DefaultConfig.hpp
	${INCLUDE_DIRECTORY}/Metric/MetricInterface.hpp
	${INCLUDE_DIRECTORY}/Metric/TotalMass.hpp
)

add_library( DroneOptimize 
	${DRONEOPTIMIZE_SOURCES}
	${DRONEOPTIMIZE_INCLUDES}
)
target_link_libraries( DroneOptimize Drone)


add_executable( TestPopulate ${TEST_DIRECTORY}/TestPopulate.cpp )
target_link_libraries( TestPopulate Drone )


add_executable( TestGenerate ${TEST_DIRECTORY}/TestGenerate.cpp )
target_link_libraries( TestGenerate DroneOptimize )
target_link_libraries( TestGenerate Drone )


#actual software
#add_executable( OptimalDrone ${SOURCE_DIRECTORY}/gar.cpp )
#target_link_libraries( gar 
#	gps_type
#	LocationSolver
#	DataCollection
#)
