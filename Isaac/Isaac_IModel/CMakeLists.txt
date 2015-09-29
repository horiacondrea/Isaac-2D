INCLUDE_DIRECTORIES("Source/Include/")
INCLUDE_DIRECTORIES(${Isaac2D_SOURCE_DIR})

file(GLOB_RECURSE INCS "*.h")
file(GLOB_RECURSE SRCS "*.cpp")

add_library(Isaac_IModel SHARED ${SRCS} ${INCS})