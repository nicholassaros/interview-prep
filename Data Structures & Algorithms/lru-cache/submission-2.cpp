class LRUCache {
public:

    struct CacheNode {
        int key;
        int val;
    };

    int _capacity;
    list<CacheNode> nodeList;
    unordered_map<int, list<CacheNode>::iterator> cache;

    LRUCache(int capacity) {
        _capacity = capacity;
    }
    
    int get(int key) {
        // if not in cache ret -1
        if(!cache.contains(key)) {
            return -1;
        }

        auto it = cache[key];
        nodeList.splice(nodeList.begin(), nodeList, it);
        return it->val;
    }
    
    void put(int key, int value) {

        if(cache.contains(key)) {
            auto it = cache[key];
            it->val = value;
            nodeList.splice(nodeList.begin(), nodeList, it);
            return;
        }

        if(cache.size() >= _capacity) {
            auto it = prev(nodeList.end());
            cache.erase(it->key);
            nodeList.erase(it);
        }

        nodeList.push_front({key, value});
        cache[key] = nodeList.begin();
    }
};
