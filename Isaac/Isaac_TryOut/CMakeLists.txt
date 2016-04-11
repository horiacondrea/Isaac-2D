INCLUDE_DIRECTORIES(${Isaac2D_SOURCE_DIR}/Isaac_Foundation/Source/Include)
INCLUDE_DIRECTORIES(${Isaac2D_SOURCE_DIR}/Isaac_IModel/Source/Include)
INCLUDE_DIRECTORIES(${Isaac2D_SOURCE_DIR}/Isaac_Triggers/Source/Include)
INCLUDE_DIRECTORIES(${Isaac2D_SOURCE_DIR}/Isaac_Core/Source/Include)
INCLUDE_DIRECTORIES(${Isaac2D_SOURCE_DIR}/Isaac_TryOut/Source/Include)
INCLUDE_DIRECTORIES(${Isaac2D_SOURCE_DIR})

file(GLOB_RECURSE INCS "*.h")
file(GLOB_RECURSE SRCS "*.cpp")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${Isaac2D_SOURCE_DIR}/../Output")

add_library(Isaac_TryOut SHARED ${SRCS} ${INCS})
target_link_libraries(Isaac_TryOut Isaac_Triggers Isaac_Core Isaac_Foundation)

# INSTALL(TARGETS Isaac_TryOut DESTINATION ${Isaac2D_SOURCE_DIR}/../Output)
