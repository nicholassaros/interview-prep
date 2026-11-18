class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        std::set<int> _set;

        int left = 0;
        

        for(int right = 0; right < nums.size(); right++) {

            while(right-left > k) {// while window is too big
                _set.erase(nums[left]);
                left++;
            }

            if(_set.contains(nums[right])) { return true; }
            _set.insert(nums[right]);
        }
        return false;
    }
};