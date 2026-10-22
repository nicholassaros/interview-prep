class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        

        int ROW = text1.size();
        int COL = text2.size();

        vector<vector<int>> dp(ROW, vector<int>(COL, 0));

        for(int r = ROW-1; r >= 0; r--) {
            for(int c = COL-1; c >= 0; c--) {

                if(text1[r] == text2[c]) {
                    // take diag
                    if(r + 1 < ROW && c + 1 < COL) {
                        dp[r][c] = dp[r+1][c+1] + 1;
                    } else {
                        dp[r][c] = 1;
                    }

                } else {
                    // find max between left and down pos
                    if(r + 1 < ROW && c + 1 < COL) {
                        dp[r][c] = max(dp[r+1][c], dp[r][c+1]);

                    } else if(r + 1 < ROW) {
                        dp[r][c] = max(dp[r+1][c], 0);

                    } else if(c + 1 < COL) {
                        dp[r][c] = max(0, dp[r][c+1]);

                    } else {
                        dp[r][c] = 0;
                    }
                }
            }
        }

        return dp[0][0];
    }
};
