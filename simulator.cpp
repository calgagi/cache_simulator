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

/***************************************
 * Func: execute()
 * Desc: Executes instruction that is
 *       inputted. Returns true if success. */
bool execute(char const& instr, string const& addr) {
    long long size, address, comma_pos = addr.find(',');
    if (comma_pos != string::npos) {
        string str_size = addr.substr(comma_pos+1);
        if (str_size.length() == 0) return false;
        try {
            size = atoi(str_size.c_str());
        } catch (exception &e) {
            cerr << "simulator, execute: Bad atoi" << endl;
            return false;
        }
        string just_addr = addr.substr(0, comma_pos);
        address = stoull(just_addr, nullptr, 16);
    } else return false;
   
    if (instr == 'S') return store(address, size);
    else if (instr == 'L') return load(address, size);
    else if (instr == 'M') return modify(address, size);
    return false;
}


