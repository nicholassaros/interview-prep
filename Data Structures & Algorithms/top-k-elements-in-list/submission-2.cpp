class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        std::unordered_map<int,int> freqMap;
        std::priority_queue<std::pair<int,int>> max_heap;
        std::vector<int> res;

        for(auto& num : nums) {
            freqMap[num]++;
        }

        for(auto& [num, freq] : freqMap) {
            max_heap.push(std::make_pair(freq,num));
        }

        for(int i = 0; i<k; i++) {
            res.push_back(max_heap.top().second);
            max_heap.pop();
        }
        return res;
    }
};

/*
get mapping of freq

store in heap as a pair of freq, number

pop from heap k times



*/
