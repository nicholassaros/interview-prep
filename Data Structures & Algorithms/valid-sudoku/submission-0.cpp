class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        unordered_map<int, unordered_set<int>> rowMap;
        unordered_map<int, unordered_set<int>> colMap;
        map<pair<int,int>, unordered_set<int>> squareMap;



        int ROW = board.size();
        int COL = board[0].size();

        for(int r = 0; r < ROW; r++) {
            for(int c = 0; c<COL; c++) {

                if(board[r][c] == '.') { continue; }

                int num = board[r][c] - '0';

                if(rowMap[r].contains(num) 
                    || colMap[c].contains(num) 
                    || squareMap[{r/3,c/3}].contains(num)) {
                        return false;
                }

                rowMap[r].insert(num);
                colMap[c].insert(num);
                squareMap[{r/3,c/3}].insert(num);

            }
        }

        return true;
        
    }
};


/*
use 3 maps, one for col, one for row, one for grid
maps have key and value is a set


*/
