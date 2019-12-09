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
    hits = misses = evictions = 0;
    // Make minicaches
    index = vector<LRU_Cache>(num_sets, LRU_Cache(associativity));
    return true;
}

/**************************************
 * Func: store()
 * Desc: Performs store operation at the
 *       given address. */
int Cache::store(long long address) {
    
}
 
/**************************************
 * Func: load()
 * Desc: Performs load operation at the
 *       given address. */
int Cache::load(long long address) {}
 
/**************************************
 * Func: modify()
 * Desc: Performs modify operation at the
 *       given address. */
int Cache::modify(long long address) {}
 
/**************************************
 * GETTERS AND SETTERS */
long long Cache::get_hits() {
    return this->hits;
}

long long Cache::get_misses() {
    return this->misses;
}

long long Cache::get_evictions() {
    return this->evictions;
}
