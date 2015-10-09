INCLUDE_DIRECTORIES(${Isaac2D_SOURCE_DIR}/Isaac_Foundation/Source/Include)
INCLUDE_DIRECTORIES(${Isaac2D_SOURCE_DIR})

file(GLOB_RECURSE INCS "*.h")
file(GLOB_RECURSE SRCS "*.cpp")

add_library(Isaac_Foundation SHARED ${SRCS} ${INCS})
target_link_libraries(Isaac_Foundation Isaac_IModel)

INSTALL(TARGETS Isaac_Foundation DESTINATION ${Isaac2D_SOURCE_DIR}/../output)