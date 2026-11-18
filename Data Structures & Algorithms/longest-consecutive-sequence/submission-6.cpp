class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::set<int> numSet;
        int res = 0;

        for(auto& num : nums) {
            numSet.insert(num);
        }

        for(auto& num : numSet) {


            int curr = num;
            while(numSet.contains(curr)) {
                curr++;
            }
            res = max(res, curr-num);
        }

        return res;


    }
};


/*
store all elem in a hash map
iter through map
if element-1 not in the map we can start looping
while element+1 in map keep looping
track longest

*/
