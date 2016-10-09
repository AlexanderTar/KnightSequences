#include <iostream>
#include <string>
#include <limits>
#include <recursivepathfinder.hpp>
#include <dppathfinder.hpp>
#include <memopathfinder.hpp>

#include <inputparser.hpp>

typedef enum {
    RECURSIVE = 1,
    MEMO = 2,
    DP = 3
} Algorithm;

int main(int argc, char** argv)
{
    std::shared_ptr<PathFinder::PathFinder> pf;
    // default values are length = 17, number of vowels = 2, algoritm - DP
    int mode = 3, sequenceLength = 17, numVowelsAllowed = 2;
    bool trace;
    std::string modeText;
    
    InputParser ip(argc, argv);
    
    if (ip.cmdOptionExists("-h"))
    {
        std::cout << "Usage: " << argv[0] << "-m MODE -l LENGTH -v NUM_VOWELS_ALLOWED [--trace]\n";
        return 0;
    }
    
    trace = ip.cmdOptionExists("--trace");
    
    if (ip.cmdOptionExists("-m"))
    {
        mode = ip.getCmdOption<int>("-m");
    }
    
    if (ip.cmdOptionExists("-l"))
    {
        sequenceLength = ip.getCmdOption<int>("-l");
    }
    
    if (ip.cmdOptionExists("-v"))
    {
        numVowelsAllowed = ip.getCmdOption<int>("-v");
    }
    
    switch (mode)
    {
        case RECURSIVE:
            pf = std::make_shared<PathFinder::RecursivePathFinder>();
            modeText = "recursive";
            break;
        case MEMO:
            pf = std::make_shared<PathFinder::MemoPathFinder>();
            modeText = "memorizing";
            break;
        case DP:
            pf = std::make_shared<PathFinder::DPPathFinder>();
            modeText = "DP";
            break;
        default:
            std::cerr << "Invalid mode specified. Available modes: 1 - recursive, 2 - memorizing, 3 - DP\n";
            return 1;
    }
    
    if (sequenceLength <= 0)
    {
        std::cerr << "Sequence length must be positive\n";
        return 1;
    }
    
    if (numVowelsAllowed < 0)
    {
        std::cerr << "Number of allowed vowels must be non-negative\n";
        return 1;
    }
    
    auto t1 = std::chrono::high_resolution_clock::now();
    size_t val = pf->countAllPaths(sequenceLength, numVowelsAllowed);
    auto t2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> ms = t2 - t1;
    std::cout << val << std::endl;
    if (trace)
        std::cout << "Calculated number of possible sequences of length "
                  << sequenceLength
                  << " with "
                  << numVowelsAllowed
                  << " vowels allowed using "
                  << modeText
                  << " algorithm. Result: "
                  << val
                  << " , took: "
                  << ms.count()
                  << " ms.\n";
    return 0;
}
