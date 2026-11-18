class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        
        
        int currentLen = 0; int maxLen = 0; int previous = 0;

        for (int i = 0; i<nums.size(); i++) {
            if (i == 0) {
                currentLen++;

            } else if (previous == nums[i]) {
               currentLen = currentLen;

            } else if (previous + 1 != nums[i]) {
                currentLen = 1;
            } else {
                currentLen++;
            }

            maxLen = max(maxLen, currentLen);
            previous = nums[i];
        }

        return maxLen;
    }
};

/*
Req : O(N) time. Linear scan

Brute force:
    - Sort
    - Itterate and expand window sequence

Pattern:
    - No sliding window
    - No 








*/