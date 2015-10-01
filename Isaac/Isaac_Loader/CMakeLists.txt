INCLUDE_DIRECTORIES(${Isaac2D_SOURCE_DIR}/Isaac_Core/Source/Include)
INCLUDE_DIRECTORIES(${Isaac2D_SOURCE_DIR}/Isaac_Foundation/Source/Include)

file(GLOB_RECURSE INCS "*.h")
file(GLOB_RECURSE SRCS "*.cpp")

add_executable(Isaac_Loader ${SRCS} ${INCS})
target_link_libraries(Isaac_Loader Isaac_Foundation Isaac_Core)


INSTALL(TARGETS Isaac_Loader DESTINATION ${Isaac2D_SOURCE_DIR}/../output)