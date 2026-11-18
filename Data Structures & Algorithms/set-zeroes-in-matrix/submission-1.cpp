class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> tempMatrix = matrix;

        int ROW = matrix.size();
        int COL = matrix[0].size();


        for(int r = 0; r<ROW; r++) {
            for(int c = 0; c<COL; c++) {

                if(matrix[r][c] == 0) {

                    for(int tempR = 0; tempR < ROW; tempR++) {
                        tempMatrix[tempR][c] = 0;
                    }

                    for(int tempC = 0; tempC < COL; tempC++) {
                        tempMatrix[r][tempC] = 0;
                    }
                }
            }
        }


        for(int r = 0; r<ROW; r++) {
            for (int c = 0; c<COL; c++) {
                matrix[r][c] = tempMatrix[r][c];
            }
        }


    }
};
