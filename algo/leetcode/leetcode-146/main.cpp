#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class LRUCache {
    int _capacity = 0;
    unordered_map<int, pair<int, list<int>::iterator>> _cache;
    list<int> _lru;
public:
    LRUCache(int capacity) {
        _capacity = capacity;
    }

    int get(int key) {
        auto item = _cache.find(key);
        // Not found
        if (item == _cache.end()) {
            return -1;
        }
        update(item);
        return item->second.first;
    }

    void put(int key, int value) {
        auto item = _cache.find(key);

        // Found
        if (item != _cache.end()) {
            update(item);
            _cache[key] = { value, _lru.begin() };
            return;
        }

        // Not Found
        if (_cache.size() >= _capacity) {
            _cache.erase(_lru.back());
            _lru.pop_back();
        }

        _lru.push_front(key);
        _cache[key] = { value, _lru.begin() };
        return;
    }

    void update(unordered_map<int, pair<int, list<int>::iterator>>::iterator& item) {
        _lru.erase(item->second.second);
        _lru.push_front(item->first);
        item->second.second = _lru.begin();
    }
};

int main() {

    LRUCache cache(2);
    cache.put(1, 0);
    cache.put(2, 2);
    cache.get(1);
    cache.put(3, 3);
    cache.get(2);
    cache.put(4, 4);
    cache.get(1);
    cache.get(3);
    cache.get(4);
	
	return 0;
}