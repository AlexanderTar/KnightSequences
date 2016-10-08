#ifndef MEMOPATHFINDER
#define MEMOPATHFINDER

#include <pathfinder.hpp>
#include <keypad.hpp>

// Recursive brute-force algorithm which is memorizing results of
// sub-problems. It is recursively iterating until either given lenght
// is achieved or allowed number of vowels exceeded. Its performance
// is comparable to DP solution, however it requires more memory

namespace PathFinder {
class MemoPathFinder : public PathFinder {
public:
    count_t countAllPaths(int sequenceLength,
                          int numVowelsAllowed);
private:
    count_t countAllPaths(const Moves& moves,
                          int sequenceLength,
                          int numVowelsAllowed);
    
    typedef std::vector<count_t> MemoLength;
    typedef std::vector<MemoLength> MemoVowels;
    typedef std::vector<MemoVowels> MemoKeys;
    MemoKeys m_memory;
};
}

#endif
