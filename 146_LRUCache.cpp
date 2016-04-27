/****************************************************************
Design and implement a data structure for Least Recently Used (LRU) cache. 
It should support the following operations: get and set.
get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. 
When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
****************************************************************/
class LRUCache{
public:
    struct node {
        int key, val;
        node(){}
        node(int k, int v) : key(k), val(v) {}
    };
    list<node> cl;
    unordered_map<int, list<node>::iterator> um;
    int capacity;
    int cnt = 0;
    
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    void move_to_head(int key) {
        if (cnt == 1) return ;
        auto it = um[key];
        node tmp(it->key, it->val);
        cl.erase(it);
        cl.push_front(tmp);
        um[key] = cl.begin();
    }
    
    int get(int key) {
        if (um.find(key) == um.end()) return -1;
        move_to_head(key);
        return um[key]->val;
    }
    
    void set(int key, int value) {
         if (um.find(key) != um.end()) {
             um[key]->val = value;
             move_to_head(key);
         } else {
             if (cnt == capacity) {
                 um.erase(cl.back().key);
                 cl.pop_back();
                 cnt--;
             }
             cl.push_front(node(key, value));
             um[key] = cl.begin();
             cnt++;
         }
    }
};