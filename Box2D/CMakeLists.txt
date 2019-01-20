set(CMAKE_TOOLCHAIN_FILE Toolchain.cmake)
project(Box2D)

set(FLAGS -Wall)

set(BOX2D_DIR include)

file(GLOB BOX2D_SRC
	Collision/*.cpp
	Collision/Shapes/*.cpp
	Common/*.cpp
	Dynamics/*.cpp
	Dynamics/Contacts/*.cpp
	Dynamics/Joints/*.cpp
	Rope/*.cpp)

add_library(${PROJECT_NAME} ${BOX2D_SRC})
target_include_directories(${PROJECT_NAME} PUBLIC ${BOX2D_DIR})
target_compile_options(${PROJECT_NAME} PUBLIC ${FLAGS} -Wno-narrowing)
