#ifndef RECURSIVEPATHFINDER
#define RECURSIVEPATHFINDER

#include <pathfinder.hpp>
#include <keypad.hpp>

// The most basic brute-force algorithm to get number of all available
// paths. It is recursively iterating until either given lenght
// is achieved or allowed number of vowels exceeded.
// This algorithm has exponential complexity of O(length^keys)

namespace PathFinder {
class RecursivePathFinder : public PathFinder {
public:
    count_t countAllPaths(int sequenceLength,
                          int numVowelsAllowed);
private:
    count_t countAllPaths(const Moves& moves,
                          int sequenceLength,
                          int numVowelsAllowed);
};
}

#endif
