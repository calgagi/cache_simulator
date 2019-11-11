/*****************************************
 * Proj: Cache Simulator
 * File: header.hpp 
 * Auth: Calvin Gagliano */

#pragma once
#include<bits/stdc++.h>

using namespace std;

/****************************************
 * Cache Class
 ****************************************/
class Cache {
    private:
        int num_sets;
        int block_size;
        int associativity;
        bool replacement_policy;
        bool write_policy;
        int access_cycles;

    public:
        bool setup(fstream&);
};


/****************************************
 * Simulator Class
 ****************************************/
class Simulator {
    private:
        int num_caches;
        long long main_mem_access_cycles;
        vector<Cache> caches;
        fstream output;

    public:
        Simulator(fstream&);
        bool execute(char const&, string const&);
        bool create_output(string const&);
};
