/*****************************************
 * Proj: Cache Simulator
 * File: simulator.cpp 
 * Auth: Calvin Gagliano */

#include "header.hpp"

/*****************************************
 * Func: Simulator()
 * Desc: Populates simulator class with
 *       input from file. Then, sets up
 *       simulator instance. */
Simulator::Simulator(fstream& config) {
    config >> num_caches;
    config >> main_mem_access_cycles;
    caches.resize(num_caches);
    for (Cache& c : caches)
        if (!c.setup(config)) {
            cerr << "simulator: constructor: Bad config file input" << endl;
            exit(0);
        }
    return;
}

