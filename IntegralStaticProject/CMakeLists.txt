# CMakeList.txt : CMake project for IntegralStaticProject, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (IntegralStaticProject "IntegralStaticProject.cpp" "IntegralStaticProject.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET IntegralStaticProject PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
