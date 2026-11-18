class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        std::map<int,int> freqMap;
        std::vector<int> res;
        std::priority_queue<std::pair<int,int>> maxHeap;

        for(auto& num : nums) {
            freqMap[num]++;
        }

        for(auto& [num, freq] : freqMap) {
            maxHeap.push({freq, num});
        }

        for(int i = 0; i<k; i++) {
            auto heapElement = maxHeap.top();
            maxHeap.pop();

            res.push_back(heapElement.second);
        }

        return res;


    }
};


/*

group elements in a map
push to priority queue
pop3 times from PQ

*/