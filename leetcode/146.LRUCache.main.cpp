class LRUCache {
public:
    LRUCache(int c) : capacity(c) {
        
    }
    
    int get(int key) {
        int result(-1);
		if (this->CacheHashMap.count(key)) {
			result = this->CacheHashMap[key]->value;
			this->CacheList.splice(this->CacheList.begin(), this->CacheList, this->CacheHashMap[key]);
			this->CacheHashMap[key] = this->CacheList.begin();
		}
		return result;
    }
    
    void put(int key, int value) {
        if (this->CacheHashMap.count(key)) {
			this->CacheHashMap[key]->value = value;
			this->CacheList.splice(this->CacheList.begin(), this->CacheList, this->CacheHashMap[key]);
			this->CacheHashMap[key] = this->CacheList.begin();
		}
		else {
			if (this->CacheList.size() >= this->capacity) {
				this->CacheHashMap.erase(this->CacheList.back().key);
				this->CacheList.pop_back();
			}
			this->CacheList.push_front(CacheNode(key, value));
			this->CacheHashMap[key] = this->CacheList.begin();
		}
    }
private:
    struct CacheNode {
		int key;
		int value;
		CacheNode(const int& k, const int& v): key(k), value(v) {}
	};
	list<CacheNode> CacheList;
	unordered_map<int, list<CacheNode>::iterator> CacheHashMap;
	int capacity;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */