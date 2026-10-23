class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1,
                                  vector<int>& nums2) {
        // Search the shorter array without modifying either input.
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        const auto& A = nums1;
        const auto& B = nums2;

        int m = A.size();
        int n = B.size();
        int total = m + n;
        int half = (total + 1) / 2;

        int l = 0;
        int r = m;

        while (l <= r) {
            int i = l + (r - l) / 2;
            int j = half - i;

            int ALeft  = i > 0 ? A[i - 1] : INT_MIN;
            int ARight = i < m ? A[i] : INT_MAX;
            int BLeft  = j > 0 ? B[j - 1] : INT_MIN;
            int BRight = j < n ? B[j] : INT_MAX;

            if (ALeft <= BRight && BLeft <= ARight) {
                if (total % 2 != 0) {
                    return max(ALeft, BLeft);
                }

                return (static_cast<double>(max(ALeft, BLeft))
                        + min(ARight, BRight)) / 2.0;
            } else if (ALeft > BRight) {
                r = i - 1;
            } else {
                l = i + 1;
            }
        }

        return -1;
    }
};
