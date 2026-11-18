class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int left = 0;
        int right = numbers.size()-1;

        while(left < right) {
            int curSum = numbers[left] + numbers[right];

            if(curSum == target) {
                return {left+1, right+1};
            } else if (curSum < target) {
                left++;
            } else {
                right--;
            }
        }
        return {-1};
    }
};

/*

left and right ptr

sum and if sum is less than target move left ptr

else move right ptr

*/
