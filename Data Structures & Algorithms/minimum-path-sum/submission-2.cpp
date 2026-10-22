class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int ROW = grid.size();
        int COL = grid[0].size();

        vector<vector<int>> dp(ROW+1, vector<int>(COL+1, 201));
        for(int r = 0; r < ROW; r++) {
            for(int c = 0; c< COL; c++) {
                dp[r][c] = grid[r][c];
            }
        }



        for(int r = ROW-1; r >= 0; r--) {
            for(int c = COL-1; c >= 0; c--) {
                if(r == ROW-1 && c == COL-1) {
                    continue;
                }

                dp[r][c] = dp[r][c] + min(dp[r+1][c], dp[r][c+1]);
            }
        }

        return dp[0][0];
    }
};