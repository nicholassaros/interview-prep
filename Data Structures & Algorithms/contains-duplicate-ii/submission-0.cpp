class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        

        std::unordered_map<int,int> duplicateMap;

        for(int i = 0; i<nums.size(); i++) {
            if (duplicateMap.contains(nums[i])) {

                if(abs(duplicateMap[nums[i]] - i) <= k){
                    return true;
                }
            }

            duplicateMap[nums[i]] = i;
        }
        return false;
    }
};