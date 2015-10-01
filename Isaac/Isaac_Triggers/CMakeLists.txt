INCLUDE_DIRECTORIES(${Isaac2D_SOURCE_DIR}/Isaac_Foundation/Source/Include)
INCLUDE_DIRECTORIES(${Isaac2D_SOURCE_DIR}/Isaac_IModel/Source/Include)
INCLUDE_DIRECTORIES(${Isaac2D_SOURCE_DIR}/Isaac_Triggers/Source/Include)
INCLUDE_DIRECTORIES(${Isaac2D_SOURCE_DIR})

file(GLOB_RECURSE INCS "*.h")
file(GLOB_RECURSE SRCS "*.cpp")

add_library(Isaac_Triggers SHARED ${SRCS} ${INCS})
target_link_libraries(Isaac_Triggers Isaac_IModel)

INSTALL(TARGETS Isaac_Triggers DESTINATION ${Isaac2D_SOURCE_DIR}/../output)