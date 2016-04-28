INCLUDE_DIRECTORIES(${Isaac2D_SOURCE_DIR}/Isaac/Isaac_Foundation/Source/Include)
INCLUDE_DIRECTORIES(${Isaac2D_SOURCE_DIR}/Isaac/common)

file(GLOB_RECURSE INCS "*.h")
file(GLOB_RECURSE SRCS "*.cpp")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${Isaac2D_SOURCE_DIR}/Output")

add_library(Isaac_isaac SHARED ${SRCS} ${INCS})
target_link_libraries(Isaac_isaac Isaac_IModel)

# INSTALL(TARGETS Isaac_isaac DESTINATION ${Isaac2D_SOURCE_DIR}/../Output)
