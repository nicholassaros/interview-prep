class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int maxCount = 0;

        std::set<int> numSet{};
        
        for (const auto& num : nums) {
            numSet.insert(num);
        }

        for (const auto& num : numSet) {
            if (!numSet.contains(num - 1)) {
                // starting num
                int count = 1;

                while(numSet.contains(num + count)) {
                    count++;
                }

                maxCount = max(maxCount, count);
            }
        }

        return maxCount;
    }
};

/*

    Itterate in one pass
        - save all nums in a set

    Itterate over set 
        - if num -1 not in set
            - while(num+1 in set)
                - record len
*/
