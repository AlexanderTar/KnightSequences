set (SRC 
	main.cpp
	inputparser.hpp
    util.hpp
)

add_executable(pathfinder.app ${SRC})
target_link_libraries(pathfinder.app pathfinderlib)
