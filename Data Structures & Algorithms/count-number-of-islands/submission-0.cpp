class Solution {
public:
    int ROW = 0;
    int COL = 0;
    vector<vector<char>> grid;

    void dfs(int r, int c) {
        if (r < 0 || c < 0 || r >= ROW || c >= COL || grid[r][c] == '0') {
            return;
        }

        grid[r][c] = '0';

        dfs(r + 1, c);
        dfs(r - 1, c);
        dfs(r, c + 1);
        dfs(r, c - 1);
    }

    int numIslands(vector<vector<char>>& inputGrid) {
        grid = inputGrid;

        ROW = grid.size();
        COL = grid[0].size();

        int res = 0;

        for (int r = 0; r < ROW; r++) {
            for (int c = 0; c < COL; c++) {
                if (grid[r][c] == '1') {
                    dfs(r, c);
                    res++;
                }
            }
        }

        return res;
    }
};
