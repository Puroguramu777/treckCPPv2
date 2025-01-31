# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\TrekAgency_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\TrekAgency_autogen.dir\\ParseCache.txt"
  "TrekAgency_autogen"
  )
endif()
