class Solution {
public:
    int maxArea(vector<int>& heights) {
        

        int left = 0; int right = heights.size()-1;

        int maxVolume = 0;

        while(left < right) {
            int currentVolume = min(heights[left],heights[right]) * (right - left);

            maxVolume = max(maxVolume, currentVolume);

            if (heights[left] < heights[right]) {
                left++;
            } else {
                right--;
            } 
        }

        return maxVolume;
    }
};


/*

left and right ptr at either side 

calc the max ammount of water min(left, right) * (right - left) +1

move the smaller ptr


*/