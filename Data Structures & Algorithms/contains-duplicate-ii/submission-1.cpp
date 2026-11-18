class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        for(int i = 0; i<nums.size(); i++) {
            for(int j = 0; j<nums.size(); j++) {
                if(i == j) { continue; }
                
                if(nums[i] == nums[j] && abs(i - j) <= k) {
                    return true;
                }
            }
        }
        return false;
    }
};
/*

[1,2,3,1], k = 3
1,1,2,3 



[2,1,2], k = 1
1,2,2
*/