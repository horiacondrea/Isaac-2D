INCLUDE_DIRECTORIES(${Isaac2D_SOURCE_DIR}/Isaac_IModel/Source/Include)
INCLUDE_DIRECTORIES(${Isaac2D_SOURCE_DIR}/Isaac_CModel/Source/Include)
INCLUDE_DIRECTORIES(${Isaac2D_SOURCE_DIR}/Isaac_Triggers/Source/Include)
INCLUDE_DIRECTORIES(${Isaac2D_SOURCE_DIR}/Isaac_Foundation/Source/Include)
INCLUDE_DIRECTORIES(${Isaac2D_SOURCE_DIR})

file(GLOB_RECURSE INCS "*.h")
file(GLOB_RECURSE SRCS "*.cpp")

add_library(Isaac_Core SHARED ${SRCS} ${INCS})
target_link_libraries(Isaac_Core Isaac_Foundation)

INSTALL(TARGETS Isaac_Core DESTINATION ${Isaac2D_SOURCE_DIR}/../output)