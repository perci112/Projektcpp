# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\ProjektCPP_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\ProjektCPP_autogen.dir\\ParseCache.txt"
  "ProjektCPP_autogen"
  )
endif()
