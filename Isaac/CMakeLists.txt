cmake_minimum_required (VERSION 2.6)

project (Isaac2D)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 1.6 REQUIRED system window graphics network audio)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
# target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()

find_package(Boost 1.54.0 REQUIRED)
if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIR})
# target_link_libraries(${EXECUTABLE_NAME} ${Boost_LIBRARIES})
endif()

add_definitions(-std=c++11)

add_subdirectory(Isaac_IModel)
add_subdirectory(Isaac_CModel)
add_subdirectory(Isaac_Triggers)
add_subdirectory(Isaac_Core)
add_subdirectory(Isaac_Foundation)
add_subdirectory(Isaac_TryOut)
add_subdirectory(Isaac_Loader)
#add_subdirectory(Isaac_ThirdParty)