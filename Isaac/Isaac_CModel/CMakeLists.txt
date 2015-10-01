INCLUDE_DIRECTORIES(${Isaac2D_SOURCE_DIR}/Isaac_IModel/Source/Include)
INCLUDE_DIRECTORIES(${Isaac2D_SOURCE_DIR}/Isaac_CModel/Source/Include)
INCLUDE_DIRECTORIES(${Isaac2D_SOURCE_DIR})

file(GLOB_RECURSE INCS "*.h")
file(GLOB_RECURSE SRCS "*.cpp")

add_library(Isaac_CModel SHARED ${SRCS} ${INCS})
target_link_libraries(Isaac_CModel Isaac_IModel)

INSTALL(TARGETS Isaac_CModel DESTINATION ${Isaac2D_SOURCE_DIR}/../output)