class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {


        int ROW = matrix.size();
        int COL = matrix[0].size();
        
        vector<bool> rowZeros(matrix.size(), false);
        vector<bool> colZeros(matrix[0].size(), false);



        for(int r = 0; r<ROW; r++) {
            for(int c = 0; c<COL; c++) {

                if(matrix[r][c] == 0) {

                    rowZeros[r] = true;
                    colZeros[c] = true;
                }
            }
        }


        for(int r = 0; r<ROW; r++) {
            for(int c = 0; c<COL; c++) {

                if(rowZeros[r] || colZeros[c]) {
                    matrix[r][c] = 0;
                }
            }
        }


    }
};
