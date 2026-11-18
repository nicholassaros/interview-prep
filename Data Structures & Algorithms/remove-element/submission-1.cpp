class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
      // set swap_index = 0
      // loop through
      // swap and incrment only when number is not val
      int swap_index = 0;

      for(int i = 0; i<nums.size(); i++){
        if(nums[i] != val) {
            swap(nums[i], nums[swap_index]);
            swap_index+=1;
        }
      }
      return swap_index;
    }
};

