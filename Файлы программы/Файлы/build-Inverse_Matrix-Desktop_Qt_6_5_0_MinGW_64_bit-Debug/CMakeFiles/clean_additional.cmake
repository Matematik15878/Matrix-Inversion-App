# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Inverse_Matrix_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Inverse_Matrix_autogen.dir\\ParseCache.txt"
  "Inverse_Matrix_autogen"
  )
endif()
