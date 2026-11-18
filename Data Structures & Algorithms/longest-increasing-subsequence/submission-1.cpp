class Solution {
public:

    vector<int> nums;
    vector<vector<int>> memo;

    int lengthOfLIS(vector<int>& _nums) {
        nums = _nums;
        vector<vector<int>> _memo(nums.size()+1, vector<int>(nums.size()+1, -1));

        memo = _memo;
        return findLIS(0, -1);
    }

    int findLIS(int index, int prevIndex) {

        if(memo[index][prevIndex+1] != -1) {
            return memo[index][prevIndex+1];
        }

        if(index >= nums.size()) {
            return 0;
        }

        int skip = findLIS(index+1, prevIndex);

        int take = 0;
        if(prevIndex == -1 || nums[index] > nums[prevIndex]) {
            take = findLIS(index+1, index) +1;
        }

        memo[index][prevIndex+1] = max(skip, take);

        return max(skip, take);
    }
};
