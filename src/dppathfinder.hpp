#ifndef DPPATHFINDER
#define DPPATHFINDER

#include <pathfinder.hpp>

// Efficient Dynamic Programming algorithm.
// It is creating a two-dimensional array to store numbers of
// possible sequences for each key and number of vowels. Works from
// the bottom up. Complexity - O(length * vowels)

namespace PathFinder {
class DPPathFinder : public PathFinder {
public:
    count_t countAllPaths(int sequenceLength,
                          int numVowelsAllowed);
};
}

#endif
