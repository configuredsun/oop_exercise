cmake_minimum_required(VERSION 2.8)
project(oop_exercise_03)
set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/../)
	

add_executable(${PROJECT_NAME} oop_exercise_03.cpp)

	
install(TARGETS ${PROJECT_NAME} DESTINATION bin)