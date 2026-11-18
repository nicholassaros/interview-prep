class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> numSet;
        int maxLength = 0;

        for(auto& num : nums) {
            numSet.insert(num);
        }

        for (auto& num : nums) {
            // check if this is a start node
            if (numSet.find(num) != numSet.end() 
                && numSet.find(num-1) == numSet.end()) {
                
                int length = 1;
                
                while(numSet.find(num+1) != numSet.end()) {
                    length+=1;
                    num+=1;
                }

                maxLength = max(maxLength, length);
            }
        }
        
        return maxLength;
    }
};

// how can we track sequences
// how do we determine when to start a new sequence
// if we sort this becomes o(N logN)

// cache all nums in a map

// loop from 0 to max number

// track sequence from that loop
// if current number is in the map we increase count
// if not we reset count

