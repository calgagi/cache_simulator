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
    if (!cache.setup(config)) {
        cerr << "simulator: constructor: Bad config file input" << endl;
        exit(0);
    }
    return;
}

/***************************************
 * Func: execute()
 * Desc: Executes instruction that is
 *       inputted. Returns true if success. */
bool execute(string const& line, char const& instr, string const& addr) {
    long long size, address, comma_pos = addr.find(',');
    if (comma_pos != string::npos) {
        string just_addr = addr.substr(0, comma_pos);
        address = stoull(just_addr, nullptr, 16);
    } else return false;

    output << line << " ";
    if (instr == 'S') store(address);
    else if (instr == 'L') load(address);
    else if (instr == 'M') modify(address);
    return true;
}

/***************************************
 * Func: complete()
 * Desc: Completes the program by printing 
 *       simulation summary. */
void complete() {
    output << "L" << i << " Cache: ";
    output << "Hits: " << caches[i].hits() << " ";
    output << "Misses: " << caches[i].misses() << " ";
    output << "Evictions: " << caches[i].evictions() << " ";
    output << endl;
    output << "Cycles:" << this->cycles << " ";
    output << "Reads:" << this->reads << " " ;
    output << "Writes: " << this->writes << " ";
    output << endl;
}

/**************************************
 * Func: store()
 * Desc: Performs store operation at the
 *       given address. */
void store(long long address) {
    
