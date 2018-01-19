#Set CXX flags to compile with c++11 and error warnings quiet
set(CMAKE_CXX_FLAGS "-O3 -fPIC -Wall -Wextra -m64")

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# You need to tell CMake where to find the ROOT installation. This can be done in a number of ways:
if(EXISTS $ENV{ROOTSYS}/cmake/ROOTConfig.cmake)
  list(APPEND CMAKE_PREFIX_PATH $ENV{ROOTSYS})
else()
  list(APPEND CMAKE_MODULE_PATH $ENV{ROOTSYS}/etc/cmake)
endif()
find_package(ROOT REQUIRED COMPONENTS RIO Net)
include(${ROOT_USE_FILE})

#produce executables in bin path
set(EXECUTABLE_OUTPUT_PATH bin)

#add executable 
add_executable( HelloSayer    HelloSayer.cxx  ${SRCS})

#link the executable with the root libraries
target_link_libraries(HelloSayer ${ROOT_LIBRARIES})
