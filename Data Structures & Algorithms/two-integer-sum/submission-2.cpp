class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    
        unordered_map<int,int> numsMap;
        // {NUMBER, INDEX}

        for(int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if(numsMap.find(complement) != numsMap.end()) {
                return {numsMap[complement], i};
            }
            numsMap[nums[i]] = i;
        }

        return {0, 0};
    }
};
