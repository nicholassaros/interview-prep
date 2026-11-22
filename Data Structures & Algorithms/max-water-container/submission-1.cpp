class Solution {
public:
    int maxArea(vector<int>& heights) {
        
        int left = 0;
        int right = heights.size()-1;

        int res = 0;

        while(left <= right) {
            int minHeight = min(heights[left], heights[right]);
            int dist = right - left;

            res = max((minHeight * dist), res);

            if(heights[left] < heights[right]) {
                left++;
            } else {
                right--;
            }
        }

        return res;

    }
};


/*

two pointers
compute max area (distance) * smallest right/left

move the smaller pointer until we cross

*/
