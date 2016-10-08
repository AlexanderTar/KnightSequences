set (SOURCE
	 recursivepathfinder.cpp
	 memopathfinder.cpp
	 dppathfinder.cpp
)

set (HEADERS
	 recursivepathfinder.hpp
	 memopathfinder.hpp
	 dppathfinder.hpp
	 pathfinder.hpp
	 keypad.hpp
)

add_library(pathfinderlib ${SOURCE} ${HEADERS})