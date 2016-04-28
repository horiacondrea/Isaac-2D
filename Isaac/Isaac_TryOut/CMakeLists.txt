INCLUDE_DIRECTORIES(${Isaac2D_SOURCE_DIR}/Isaac/Isaac_Foundation/Source/Include)
INCLUDE_DIRECTORIES(${Isaac2D_SOURCE_DIR}/Isaac/Isaac_Model/Source/Include)
INCLUDE_DIRECTORIES(${Isaac2D_SOURCE_DIR}/Isaac/Isaac_Triggers/Source/Include)
INCLUDE_DIRECTORIES(${Isaac2D_SOURCE_DIR}/Isaac/Isaac_Core/Source/Include)
INCLUDE_DIRECTORIES(${Isaac2D_SOURCE_DIR}/Isaac/Isaac_TryOut/Source/Include)
INCLUDE_DIRECTORIES(${Isaac2D_SOURCE_DIR}/Isaac/common)

file(GLOB_RECURSE INCS "*.h")
file(GLOB_RECURSE SRCS "*.cpp")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${Isaac2D_SOURCE_DIR}/Output")

add_library(Isaac_TryOut SHARED ${SRCS} ${INCS})
target_link_libraries(Isaac_TryOut Isaac_Triggers Isaac_Core Isaac_Foundation)

# INSTALL(TARGETS Isaac_TryOut DESTINATION ${Isaac2D_SOURCE_DIR}/../Output)
