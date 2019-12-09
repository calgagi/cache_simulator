/*****************************************
 * Proj: Cache Simulator
 * File: lru_cache.hpp 
 * Auth: Calvin Gagliano */

#include "./header.hpp"


/*****************************************
 * Func: Constructor
 * Desc: Sets up LRU_Cache size and capacity
 */
LRU_Cache::LRU_Cache(int c) {
    this->capacity = c;
    size = 0;
    head = tail = NULL;
}


/*****************************************
 * Func: get()
 * Desc: Returns HIT if in cache, MISS if not
 */
enum RESULT LRU_Cache::get(long long tag) {
    if (this->where.count(tag)) {
        this->put(tag);
        return HIT;
    } else return MISS;
}

/*****************************************
 * Func: put()
 * Desc: Organizes item at tag inside Cache
 *       If already in Cache: HIT
 *       If not in Cache and cache is full: EVICT
 *       If not in Cache: MISS
 */
enum RESULT LRU_Cache::put(long long tag) {
    bool evict = false, hit = false;
    if (this->where.count(tag)) {
        Node* removed = where[tag];
        if (removed->prev)
            removed->prev->next = removed->next;
        else
            head = removed->next;
        if (removed->next)
            removed->next->prev = removed->prev;
        else
            tail = removed->prev;
        where.erase(tag);
        delete removed;
        size--;
        hit = true;
    } else if (size == capacity) {
        Node* new_head = head->next;
        if (new_head) new_head->prev = NULL;
        if (head == tail) tail = NULL;
        where.erase(head->tag);
        delete head;
        head = new_head;
        size--;
        evict = true;
    }
    Node* add = new Node(NULL, NULL, tag);
    where[tag] = add;
    if (tail) {
        tail->next = add;
        add->prev = tail;
        tail = add;
    } else {
        tail = add;
        head = add;
    }
    size++;
    if (hit) return HIT;
    if (evict) return EVICTION;
    return MISS;
}
