class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        

        std::map<int,int> freqMap;
        std::vector<int> res;

        for(auto num : nums) {
            freqMap[num]++;
        }

        for(auto [num, freq] : freqMap) {
            if(freq > nums.size()/3) {
                res.push_back(num);
            }
        }
        return res;
    }
};