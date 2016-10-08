#ifndef PATHFINDER
#define PATHFINDER

#include <vector>

namespace PathFinder {
    
typedef uintmax_t count_t;

class PathFinder {
public:
    virtual count_t countAllPaths(int sequenceLength,
                                  int numVowelsAllowed) = 0;
};
}

#endif
