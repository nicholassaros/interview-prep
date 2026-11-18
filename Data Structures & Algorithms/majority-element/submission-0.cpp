class Solution {
public:
    int majorityElement(vector<int>& nums) {
        

        std::sort(nums.begin(), nums.end(), [](const int& a, const int& b){
            return a < b;
        });

        return nums[nums.size()/2];
    }
};