class TimeMap {
public:
    std::unordered_map<string, std::deque<std::pair<string,int>>> _map;

    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        // When we set, we need to add the key to the map and push the value to the stack
        if  (_map.find(key) == _map.end()) {
            _map[key];
        }
        _map[key].push_back(std::make_pair(value,timestamp));
    }
    
    string get(string key, int timestamp) {
        if (_map.find(key) == _map.end()) {
            return "";
        }



        for (auto it = _map[key].rbegin(); it != _map[key].rend(); it++) {
            auto p = *it;
            if (p.second <= timestamp) {
                return p.first;
            }
        }
        return "";
    }
};

/*

How can we store the timestamp in the map and do efficent comparisons?

Worst case is we store in a priority queue and itterate over it


*/
