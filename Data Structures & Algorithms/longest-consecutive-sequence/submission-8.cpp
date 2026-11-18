class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::set<int> numSet;
        int res = 0;

        for(auto& num : nums) {
            numSet.insert(num);
        }

        for(auto& num : nums) {
            if(!numSet.contains(num-1)) {
                int length = 0;

                while(numSet.contains(num+length)) {
                    length++;
                }

                res = max(res, length);
            }
        }

        return res;
    }
};

/*
loop over and map all elements

loop over array and only start at elements where element-1 is not in map

itterate on that element by adding 1 until not in map
*/
