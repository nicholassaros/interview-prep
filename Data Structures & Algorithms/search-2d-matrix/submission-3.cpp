class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int topRow = 0;
        int botRow = matrix.size() - 1;

        while (topRow <= botRow) {
            int midRow = topRow + (botRow - topRow) / 2;

            if (target < matrix[midRow][0]) {
                botRow = midRow - 1;
            } else if (target > matrix[midRow].back()) {
                topRow = midRow + 1;
            } else {
                int left = 0;
                int right = matrix[midRow].size() - 1;

                while (left <= right) {
                    int mid = left + (right - left) / 2;

                    if (matrix[midRow][mid] == target) {
                        return true;
                    } else if (matrix[midRow][mid] < target) {
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }

                return false;
            }
        }

        return false;
    }
};