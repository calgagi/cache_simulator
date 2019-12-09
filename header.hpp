/*****************************************
 * Proj: Cache Simulator
 * File: header.hpp 
 * Auth: Calvin Gagliano */

#pragma once
#include<bits/stdc++.h>

using namespace std;

// Result for caches
enum RESULT { MISS, HIT, EVICTION };

/****************************************
 * Node struct used in LRU_Cache
 ****************************************/
struct Node {
    Node* next;
    Node* prev;
    int tag;
    Node(Node* n, Node* p, int t) : next(n), prev(p), tag(t) {};
};

/****************************************
 * LRU_Cache Class
 ****************************************/
class LRU_Cache {
    private:
        Node* head;
        Node* tail;
        int capacity;
        int size;
        unordered_map<long long, Node*> where;

    public:
        LRU_Cache(int); 
        enum RESULT get(long long);
        enum RESULT put(long long);
};

/****************************************
 * Cache Class
 ****************************************/
class Cache {
    private:
        // Config vars
        int num_sets;
        int block_size;
        int associativity;
        bool replacement_policy;
        bool write_policy;
        int access_cycles;

        // Summary vars
        long long hits, misses, evictions;

        // O(1) caches by index
        vector<LRU_Cache> index;

    public:
        bool setup(fstream&);
        int cycles();
        int load(long long);
        int modify(long long);
        int store(long long);
        long long get_hits();
        long long get_misses();
        long long get_evictions();
};


/****************************************
 * Simulator Class
 ****************************************/
class Simulator {
    private:
        int num_caches;
        long long main_mem_access_cycles;
        Cache cache;
        fstream output;
        int total_writes, total_cycles, total_reads;

    public:
        Simulator(fstream&);
        bool execute(string const&, char const&, string const&);
        bool create_output(string const&);
        void complete();
};



