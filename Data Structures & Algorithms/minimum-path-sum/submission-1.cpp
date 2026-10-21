class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        

        int ROW = grid.size();
        int COL = grid[0].size();

        for(int r = ROW-1; r >= 0; r--) {
            for(int c = COL-1; c >= 0; c--) {

                if(r == ROW-1 && c == COL-1) {
                    continue;
                } else if(r == ROW-1) {
                    grid[r][c] = grid[r][c+1] + grid[r][c];
                } else if(c == COL-1) {
                    grid[r][c] = grid[r+1][c] + grid[r][c];
                } else {
                    grid[r][c] = min(grid[r+1][c], grid[r][c+1]) + grid[r][c];
                }
            }
        }

        return grid[0][0];
    }
};