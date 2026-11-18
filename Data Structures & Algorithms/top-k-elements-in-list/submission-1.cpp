class Solution {
public:
    struct Element {
        int freq;
        int num;

        Element(int freq, int num) :
            freq(freq), num(num) {}
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int,int> freqMap;
        vector<int> res;

        auto comparator = [](const Element& e1, const Element& e2){
            return e1.freq < e2.freq;
        };

        std::priority_queue<Element, std::vector<Element>, decltype(comparator)> pq;

        for(const auto& num : nums) {
            freqMap[num]++;
        }

        for(const auto& [num, freq] : freqMap) {
            pq.push(Element(freq, num));
        }

        for(int i = 0; i<k; i++){
            Element e = pq.top();
            res.push_back(e.num);
            pq.pop();
        }

        return res;

    }
};
