class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_map<int,int> numMap;

        for(auto num : nums) {
            if (numMap.find(num) != numMap.end()) {
                return true;
            } 

            numMap[num] = 1;
        }
        return false;
    }
};