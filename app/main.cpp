#include <iostream>
#include <string>
#include <limits>
#include <recursivepathfinder.hpp>
#include <dppathfinder.hpp>
#include <memopathfinder.hpp>

typedef enum {
    RECURSIVE = 1,
    MEMO = 2,
    DP = 3
} Algorithm;

int main(int argc, char** argv)
{
    if (argc < 4) {
        std::cerr << "Usage: " << argv[0] << "MODE LENGTH NUM_VOWELS_ALLOWED" << std::endl;
        return 1;
    }
    
    std::shared_ptr<PathFinder::PathFinder> pf;
    int mode, sequenceLength, numVowelsAllowed;
    std::string modeText;
    
    mode = atoi(argv[1]);
    sequenceLength = atoi(argv[2]);
    numVowelsAllowed = atoi(argv[3]);
    
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
    
    auto t1 = std::chrono::high_resolution_clock::now();
    size_t val = pf->countAllPaths(sequenceLength, numVowelsAllowed);
    auto t2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> ms = t2 - t1;
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
}
