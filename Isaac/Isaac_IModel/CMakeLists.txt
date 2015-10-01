INCLUDE_DIRECTORIES(${Isaac2D_SOURCE_DIR}/Isaac_IModel/Source/Include)
INCLUDE_DIRECTORIES(${Isaac2D_SOURCE_DIR})

file(GLOB_RECURSE INCS "*.h")
file(GLOB_RECURSE SRCS "*.cpp")

add_library(Isaac_IModel SHARED ${SRCS} ${INCS})
target_link_libraries(Isaac_IModel ${SFML_LIBRARIES})

INSTALL(TARGETS Isaac_IModel DESTINATION ${Isaac2D_SOURCE_DIR}/../output)