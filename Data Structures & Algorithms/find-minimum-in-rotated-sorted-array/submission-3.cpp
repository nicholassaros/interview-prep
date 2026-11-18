class Solution {
public:
    int findMin(vector<int> &nums) {

        int minNum = nums[nums.size()-1];

        int left = 0;
        int right = nums.size()-1;

        while (left <= right){

            if (nums[left] < nums[right]){
                minNum = min(minNum, nums[left]);
                break;
            } else {

                // array is sorted
                int mid = left + (right-left)/2;
                minNum = min(minNum, nums[mid]);
                if (nums[mid] >= nums[left]){
                    // search left
                    left = mid+1;
                } else {
                    right = mid-1;
                }
            }
        }

        return minNum;
        
    }
};



// 3,4,5,6,1,2

// left=3,  right=2,  mid=6
// we know it is rotated since left > right
// mid is larger than left so we search right

// left=1 right=2 mid=2
// we choose 1 but how?

// 4,5,6,7

// left=4, right=7, mid=6
// if left<right pick left



// 4,5,0,1,2,3
// left=4, mid=1, right=3
// if mid < right we search left

//left=5, mid=0 right=1


