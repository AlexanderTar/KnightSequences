#ifndef INPUTPARSER
#define INPUTPARSER

#include <algorithm>
#include <vector>

#include <util.hpp>

class InputParser{
public:
    InputParser (int& argc, char **argv)
    {
        for (int i = 1; i < argc; ++i)
            this->tokens.push_back(std::string(argv[i]));
    }
    
    template <typename T>
    T getCmdOption(const std::string &option) const
    {
        std::vector<std::string>::const_iterator itr;
        itr = std::find(this->tokens.begin(), this->tokens.end(), option);
        if (itr != this->tokens.end() && ++itr != this->tokens.end())
        {
            return std::lexical_cast<T>(*itr);
        }
        return T();
    }
    
    bool cmdOptionExists(const std::string &option) const
    {
        return std::find(this->tokens.begin(), this->tokens.end(), option)
                != this->tokens.end();
    }
private:
    std::vector<std::string> tokens;
};

#endif
