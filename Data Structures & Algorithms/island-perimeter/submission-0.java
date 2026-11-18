class Solution {

    private int[][]     m_Grid;
    private boolean[][] m_Visited;
    private int         m_Rows, m_Cols;

    public int islandPerimeter(int[][] grid) {
        this.m_Grid = grid;
        this.m_Rows = grid.length;
        this.m_Cols = grid[0].length;
        this.m_Visited = new boolean[m_Rows][m_Cols];

        for(int i = 0; i < m_Rows; i++){
            for(int j = 0; j < m_Cols; j++){
                if(m_Grid[i][j] == 1) {
                    return dfs(i,j);
                }
            }
        }
        return 0;
    }

    private int dfs(int row, int col) {
        if (
            row < 0 || 
            row >= m_Rows || 
            col < 0 || 
            col >= m_Cols || 
            m_Grid[row][col] == 0) {
                return 1;
            }
        
        if (m_Visited[row][col] == true){
            return 0;
        }
        m_Visited[row][col] = true;
        return dfs(row+1,col) + dfs(row-1,col) + dfs(row,col+1) + dfs(row,col-1);
    };
}

// we itterate through and check if island
// we call dfs to return number of sides, if invalid return 1