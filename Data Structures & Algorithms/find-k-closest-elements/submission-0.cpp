class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0; int right = arr.size()-1;

        while((right - left) >= k) {

            if (abs(arr[left] - x) <= abs(arr[right] - x)) {
                right--;
            } else {
                left++;
            }
        }

        return vector<int>(arr.begin() + left, arr.begin() + right + 1);

    }
};

/*

    - We can use a two pointer solution since the array is sorted
    - Compare left and right
    - Whichever is not closer we move
    - If the dist between left and right == K then we return

*/