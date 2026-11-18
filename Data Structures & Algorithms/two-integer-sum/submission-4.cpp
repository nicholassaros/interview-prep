class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        std::map<int,int> _map;
        

        for(int i = 0; i<nums.size(); i++) {

            int currentNum = nums[i];
            if(_map.contains(target-currentNum)) {
                return {_map[target-currentNum], i};
            }

            _map[currentNum] = i;
        }

        
    }
};
