#include <recursivepathfinder.hpp>

namespace PathFinder {
    
count_t RecursivePathFinder::countAllPaths(int sequenceLength,
                                           int numVowelsAllowed)
{
    return countAllPaths(defaultKeyPad, sequenceLength, numVowelsAllowed);
}

count_t RecursivePathFinder::countAllPaths(const Moves& moves,
                                           int sequenceLength,
                                           int numVowelsAllowed)
{
    count_t result = 0;
    
    if (sequenceLength-- > 0)
    {
        for (auto key: moves)
        {
            count_t num = 0;
            if (numVowelsAllowed > 0 ||
                !isVowel(key))
            {
                num = sequenceLength > 0
                    ? countAllPaths(KeyMap[key],
                                    sequenceLength,
                                    numVowelsAllowed - int(isVowel(key)))
                    : 1;
            }
            result += num;
        }
    }
    
    return result;
}
    
}
