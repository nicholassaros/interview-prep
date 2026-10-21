class Solution {
public:
    int maxArea(vector<int>& heights) {
        
        int left = 0;
        int right = heights.size()-1;
        int res = 0;


        while(left < right) {
            int volume = (right-left) * min(heights[left], heights[right]);
            res = max(volume, res);

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

2 ptr 
calc volume and then move ptr which has lowest num 

*/
