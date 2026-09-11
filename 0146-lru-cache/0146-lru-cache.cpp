class LRUCache {
private:
  unordered_map<int, list<pair<int,int>>::iterator> record;
  list<pair<int,int>> stored;
  int cap;
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(record.find(key) == record.end()) return -1;
        auto it = record[key];
        auto value = it->second;
        stored.erase(it);
        stored.push_back(pair(key,value));
        record[key] = prev(stored.end());
        return value;
    }
    
    void put(int key, int value) {
        if(record.find(key) != record.end()) {
            auto it = record[key];
            stored.erase(it);
        } 
        else {
            if(stored.size() == cap){
                auto h = stored.begin();
                record.erase(h->first);
                stored.pop_front();
                
            }
        }
        stored.push_back(pair(key,value));
        record[key] = prev(stored.end());
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */