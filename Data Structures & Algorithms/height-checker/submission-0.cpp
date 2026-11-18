class Solution {
public:
    int heightChecker(vector<int>& heights) {
        std::vector<int> expectedHeights = heights;
        std::sort(expectedHeights.begin(), expectedHeights.end());
        int res = 0;


        for(int i = 0; i < heights.size(); i++) {
            if (heights[i] != expectedHeights[i]) {
                res++;
            }
        }
        return res;
    }
};