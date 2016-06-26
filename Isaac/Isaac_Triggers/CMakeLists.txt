INCLUDE_DIRECTORIES(${Isaac2D_SOURCE_DIR}/Isaac/Isaac_Model/Source/Include)
INCLUDE_DIRECTORIES(${Isaac2D_SOURCE_DIR}/Isaac/Isaac_Core/Source/Include)
INCLUDE_DIRECTORIES(${Isaac2D_SOURCE_DIR}/Isaac/Isaac_Triggers/Source/Include)
INCLUDE_DIRECTORIES(${Isaac2D_SOURCE_DIR}/Isaac/common)

file(GLOB_RECURSE INCS "*.h")
file(GLOB_RECURSE SRCS "*.cpp")

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${Isaac2D_SOURCE_DIR}/Output")

add_library(Isaac_Triggers SHARED ${SRCS} ${INCS})
target_link_libraries(Isaac_Triggers Isaac_Model Isaac_Core)

# INSTALL(TARGETS Isaac_Triggers DESTINATION ${Isaac2D_SOURCE_DIR}/../Output)
