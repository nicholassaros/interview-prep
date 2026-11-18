class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for(int i = 0; i<nums.size(); i++){
            if (nums[i] > 0){
                break;
            }

            if (i > 0 && nums[i] == nums[i-1]){
                continue;
            }

            int left = i+1;
            int right = nums.size()-1;

            while(left<right){

                int cur_sum = nums[i]+nums[left]+nums[right];

                if (cur_sum == 0){
                    res.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }
                } else if (cur_sum > 0){
                    // decrement left 
                    right--;
                } else {
                    left++;
                }
            }
        }
        return res;


    }
};

// sort array

// loop through array and choose left and right as left = i+1 and right = size-1

// [-4,-1,-1,0,1,2]