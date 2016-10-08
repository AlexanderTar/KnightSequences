#include <dppathfinder.hpp>
#include <keypad.hpp>

#include <numeric>

namespace PathFinder {
    
count_t DPPathFinder::countAllPaths(int sequenceLength,
                                    int numVowelsAllowed)
{
    typedef std::vector<std::vector<count_t>> Counts;
    
    Counts snapshot((Counts::size_type)numVowelsAllowed + 1);
    Counts prevSnapshot;
    
    for (Counts::size_type v = 0; v < numVowelsAllowed; ++v)
    {
        snapshot[v].resize(defaultKeyPad.size(), 1);
    }
    
    for (auto key: defaultKeyPad)
    {
        snapshot[numVowelsAllowed].push_back(1 - int(isVowel(key)));
    }
    
    for (int i = 1; i < sequenceLength; ++i)
    {
        prevSnapshot = snapshot;
        
        for (auto key: defaultKeyPad)
        {
            for (Counts::size_type v = 0; v < snapshot.size(); ++v)
            {
                snapshot[v][key] = 0;
                if (v < numVowelsAllowed ||
                    !isVowel(key))
                {
                    for (auto nextKey: KeyMap[key])
                    {
                        snapshot[v][key] += prevSnapshot[v + int(isVowel(key))][nextKey];
                    }
                }
            }
        }
    }
    
    return std::accumulate(snapshot[0].begin(), snapshot[0].end(), 0);
}

}
