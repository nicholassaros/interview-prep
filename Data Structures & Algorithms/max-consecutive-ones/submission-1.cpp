class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int res = 0;

        int left = 0;
        for(int right = 0; right < nums.size(); right++) {

            if(nums[right] == 0) {
                left = right+1;
            }
            res = max(res, right-left+1);
        }

        return res;
    }
};


/*

expand until we reach 0

each itteration we cacl size

*/