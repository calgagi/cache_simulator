/*****************************************
 * Proj: Cache Simulator
 * File: header.hpp 
 * Auth: Calvin Gagliano */

#pragma once
#include<bits/stdc++.h>

using namespace std;


/****************************************
 * Node struct used in LRU_Cache
 ****************************************/
struct Node {
    Node* next;
    Node* prev;
    int val;
    int key;
    Node(Node* n, Node* p, int v, int k) : next(n), prev(p), val(v), key(k) {};
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
        unordered_map<int, Node*> where;

    public:
        LRU_Cache(int); 
        bool get(int, int);
        bool put(int, int);
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

        

    public:
        bool setup(fstream&);
        int cycles();
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

    public:
        Simulator(fstream&);
        bool execute(string const&, char const&, string const&);
        bool create_output(string const&);
        void store(long long, long long);
        void load(long long, long long);
        void modify(long long, long long);
        void complete();
};



