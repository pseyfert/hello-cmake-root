#Set CXX flags to compile with c++11 and error warnings quiet
set(CMAKE_CXX_FLAGS "-O3 -fPIC -Wall -Wextra -std=c++11 -m64")

#Load root 
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} $ENV{ROOTSYS}/etc/cmake)
#print conf
message(STATUS "Environmental CMAKE_MODULE_PATH is $ENV{ROOTSYS}")
#find the package with extra libraries needed
find_package(ROOT MODULE REQUIRED Cling TreePlayer Tree Rint Postscript Matrix RIO Core Foam RooStats RooFit RooFitCore Gpad Graf3d Graf Hist Net TMVA  XMLIO MLP)
#include ROOT stuff
include(${ROOT_USE_FILE})
message(STATUS "Environmental ROOTSYS is $ENV{ROOTSYS}")
message(STATUS "found root at: ${ROOT_USE_FILE}")
message(STATUS "ROOT_LIBRARIES=${ROOT_LIBRARIES}")

#Grab some classes from other packages: 
#set(FROM_OTHERS_INCLUDE ./../SelectionCode/Headers ../DecayGen/Headers)
#set(FROM_OTHERS_HEADER ./../SelectionCode/Headers/CopyWithCut.hpp)
#set(FROM_OTHERS_SOURCE ./../SelectionCode/Sources/CopyWithCut.cpp)

#produce executables in bin path
set(EXECUTABLE_OUTPUT_PATH bin)
#include_directories(./../Framework Headers)
#${FROM_OTHERS_INCLUDE})
#defines all .cpp support class with corresponding Headers
#file(GLOB SRCS Sources/*.cpp Headers/*.hpp )
#${FROM_OTHERS_HEADER} ${FROM_OTHERS_SOURCE})

#add executable 
add_executable( HelloSayer    HelloSayer.cxx  ${SRCS})

#link the executable with the root libraries
target_link_libraries(HelloSayer ${ROOT_LIBRARIES})
