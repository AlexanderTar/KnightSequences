#include <memopathfinder.hpp>

#include <algorithm>

namespace PathFinder {
    
count_t MemoPathFinder::countAllPaths(int sequenceLength,
                                      int numVowelsAllowed)
{
    // initialising memory vector
    m_memory.clear();
    m_memory.resize(defaultKeyPad.size());
    for (auto key: defaultKeyPad)
    {
        m_memory[key].clear();
        m_memory[key].resize((MemoVowels::size_type)numVowelsAllowed + 1);
        for (MemoVowels::size_type v = 0; v < numVowelsAllowed + 1; ++v) {
            m_memory[key][v].clear();
            m_memory[key][v].resize((MemoLength::size_type)sequenceLength + 1);
        }
    }
    return countAllPaths(defaultKeyPad, sequenceLength, numVowelsAllowed);
}
    
count_t MemoPathFinder::countAllPaths(const Moves& moves,
                                      int sequenceLength,
                                      int numVowelsAllowed)
{
    count_t result = 0;
    if (sequenceLength-- > 0)
    {
        for (auto key: moves)
        {
            auto num = m_memory[key][numVowelsAllowed][sequenceLength];
            if (!num)
            {
                if (numVowelsAllowed > 0 ||
                    !isVowel(key))
                {
                    num = sequenceLength > 0
                        ? countAllPaths(KeyMap[key],
                                        sequenceLength,
                                        numVowelsAllowed - int(isVowel(key)))
                        : 1;
                }
                m_memory[key][numVowelsAllowed][sequenceLength] = num;
            }
            result += num;
        }
    }
    
    return result;
}
    
}
