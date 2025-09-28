#include "arena.hpp"
#include <iostream>
using namespace std;

int main(int argc, char** argv){
    {
    Arena<3, 1.1> arena; // creates three arenas 0,1, and 2. Resize factor is 1.1, i.e if an allocation of m bytes cannot
    // be satisified a new memory page will be allocated with floor(1.1*m) bytes to hold the requested memory block.
    auto m1 = arena.allocate(32, 0); 
    auto m2 = arena.allocate(32, 0);
    auto m3 = arena.allocate(32, 0);
    // Get rid of arena 0
    arena.free(0);
    auto mm = arena.allocate(32, 0);
    cout << (mm == m1) << '\n'; // should print '1'
    arena.free(0);

    m1 = arena.allocate(32, 1);
    m2 = arena.allocate(32, 1);
    m3 = arena.allocate(32, 1);
    arena.free(1,m2); // frees space occupied by m2
    auto m4 =   arena.allocate(32, 1); 
    cout << (m4 == m2) << '\n'; // should be true 
    }
   {
    Arena<3, 2.0> arena;
    auto m1 = arena.allocate(32, 0);
    auto m2 = arena.allocate(32, 0);
    auto m3 = arena.allocate(32, 0);
    // Get rid of arena 0
    arena.free(0);
    m1 = arena.allocate(32, 1);
    m2 = arena.allocate(32, 1);
    m3 = arena.allocate(32, 1);
    arena.free(1,m2); // frees space occupied by m2
    auto m4 =   arena.allocate(32, 1); 
    cout << (m4 == m2) << '\n'; // should print '0'
    }

    return 0;
}