INCLUDE_DIRECTORIES("Source/Include/")

file(GLOB_RECURSE INCS "*.h")
file(GLOB_RECURSE SRCS "*.cpp")

add_library(Isaac_IModel SHARED ${SRCS} ${INCS})