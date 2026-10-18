class LRUCache {
public:

    int cap;

    struct CacheNode {
        int key;
        int val;
    };

    list<CacheNode> nodeList;
    map<int, list<CacheNode>::iterator> cache;

    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(!cache.contains(key)) {
            return -1;
        }

        auto it = cache[key];
        nodeList.splice(nodeList.begin(), nodeList, it);
        return it->val;
    }
    
    void put(int key, int value) {
        // if not in cache

        if(cache.contains(key)) {
            auto it = cache[key];
            it->val = value;
            nodeList.splice(nodeList.begin(), nodeList, it);
            return;
        }

        if(cache.size() >= cap) {
            auto lastNode = nodeList.back();
            auto it = cache[lastNode.key];
            cache.erase(lastNode.key);
            nodeList.erase(it);
        }

        nodeList.push_front({key, value});
        cache[key] = nodeList.begin();
    
    }
};
