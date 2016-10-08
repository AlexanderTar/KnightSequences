#ifndef KEYPAD
#define KEYPAD

#include <vector>

namespace PathFinder {

// Enum defining available keys, _w is wildcard (any) symbol
typedef enum {
    A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, _1, _2, _3, _w
} Key;

inline
bool isVowel(Key key) { return key == A || key == E || key == I || key == O; }

// This is a map of possible moves for each key
// The assumption is that moving through empty space is not allowed.
// Therefore, move F -> 1 is not possible as it does not follow either of
// defined knight move rules
typedef std::vector<Key> Moves;
const std::vector<Moves> KeyMap = {
    {H, L},               // A
    {K, M, I},            // B
    {F, J, L, N},         // C
    {G, M, O},            // D
    {H, N},               // E
    {C, M},               // F
    {D, N, _2},           // G
    {A, E, K, O, _1, _3}, // H
    {B, L, _2},           // I
    {C, M},               // J
    {B, H, _2},           // K
    {A, C, I, _3},        // L
    {F, B, D, J},         // M
    {G, C, E, _1},        // N
    {D, H, _2},           // O
    {F, H, N},            // 1
    {G, I},         // 2
    {L, H, J},            // 3
    {A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, _1, _2, _3} // wildcard
};

const Moves defaultKeyPad = KeyMap[_w];
    
}

#endif
