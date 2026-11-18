class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        

        int sum = 0;
        for(int left = 0; left < nums.size(); left++) {
            int sum = 0;
            for(int right = left; right < nums.size(); right++) {
                sum+=nums[right];

                if (sum % k == 0 && right - left + 1 >= 2) {
                    return true;
                }
            }
        }

        return false;
    }
};