class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        std::set<int> numSet;
        int result = 0;

        for(const auto& num : nums){
            numSet.insert(num);
        }

        for(auto num : numSet) {
            if (numSet.find(num-1) == numSet.end()) {
                int length = 0;

                while(numSet.find(num + length) != numSet.end()) {
                    length+=1;
                }
                result = std::max(result, length);
            }
        }
        return result;


    }
};

// add all elements to a hash map
// loop over hash map to find starting value (value where value+1 in map and value-1 not in map)
// continue loop +1 until value not longer in map