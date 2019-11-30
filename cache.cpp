/*****************************************
 * Proj: Cache Simulator
 * File: cache.cpp 
 * Auth: Calvin Gagliano */

#include "header.hpp"

/*****************************************
 * Func: setup()
 * Desc: Sets up cache object by populating
 *       variables and then setting up
 *       cache. Returns true if set up successfully. 
 *       */
bool Cache::setup(fstream& config) {
    config >> num_sets;
    config >> block_size;
    config >> associativity;
    config >> replacement_policy;
    config >> write_policy;
    config >> access_cycles;
    if (cin.fail()) return false;
    return true;
}

/****************************************
 * Getters and Setters
 */
int cycles() {
    return this->cycles;
}

