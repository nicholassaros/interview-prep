class Solution {
public:
    int longestPalindromeSubseq(string s) {
        
        string sReverse = s;
        reverse(sReverse.begin(), sReverse.end());

        int ROW = s.size();
        int COL = sReverse.size();

        vector<vector<int>> dp(ROW +1, vector<int>(COL+1,0));


        for(int r = ROW-1; r >= 0; r--) {
            for(int c = COL-1; c >= 0; c--) {
                if(s[r] == sReverse[c]) {
                    dp[r][c] = 1 + dp[r+1][c+1];
                } else {
                    dp[r][c] = max(dp[r+1][c], dp[r][c+1]);
                }
            }
        }

        return dp[0][0];
    }
};