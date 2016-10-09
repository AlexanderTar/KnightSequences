#ifndef UTIL
#define UTIL

#include <string>
#include <sstream>

namespace std {
    
template <typename T>
T lexical_cast(const std::string& str)
{
    T var;
    std::istringstream iss;
    iss.str(str);
    iss >> var;
    return var;
}
    
}

#endif
