class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        

        bool monotonicIncrease = true;
        bool monotonicDecrease = true;


        for(int i = 0; i<nums.size()-1; i++) {
            int j = i+1;

            if (nums[i] < nums[j]) {
                monotonicDecrease = false;
            } else if (nums[i] > nums[j]) {
                monotonicIncrease = false;
            }

            if (!monotonicDecrease && !monotonicIncrease) {
                return false;
            }
        }

        return true;
    }
};