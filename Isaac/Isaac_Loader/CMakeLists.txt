INCLUDE_DIRECTORIES(${Isaac2D_SOURCE_DIR}/Isaac/Isaac_Core/Source/Include)
INCLUDE_DIRECTORIES(${Isaac2D_SOURCE_DIR}/Isaac/common)

file(GLOB_RECURSE INCS "*.h")
file(GLOB_RECURSE SRCS "*.cpp")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${Isaac2D_SOURCE_DIR}/Output")

add_executable(Isaac_Loader ${SRCS} ${INCS})
target_link_libraries(Isaac_Loader Isaac_Core)

# INSTALL(TARGETS Isaac_Loader DESTINATION ${Isaac2D_SOURCE_DIR}/../Output)

