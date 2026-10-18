class Solution {
public:

    int ROW;
    int COL;

    set<pair<int,int>> visited;
    vector<vector<char>> grid;


    void dfs(int r, int c) {
        if(r == ROW || c == COL || r < 0 || c < 0 || visited.contains({r,c}) || grid[r][c] == '0') {
            return;
        }

        visited.insert({r,c});
        dfs(r+1,c);
        dfs(r-1,c);
        dfs(r,c+1);
        dfs(r,c-1);
    }


    int numIslands(vector<vector<char>>& _grid) {
        grid = _grid;

        int res = 0;

        ROW = grid.size();
        COL = grid[0].size();

        for(int r = 0; r<ROW; r++) {
            for(int c = 0; c<COL; c++) {
                if(grid[r][c] == '1' && !visited.contains({r,c})) {
                    res+=1;
                    dfs(r,c);
                }
            }
        }

        return res;
    }
};
