class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int,int> buckets;
        int write_ptr = 0;

        for(auto num : nums) {
            buckets[num]++;
        }

        for(auto [bucket, size] : buckets) {

            for(int i = 0; i<size; i++) {
                nums[write_ptr] = bucket;
                write_ptr++;
            }
        }
    }
};

/*

bucket sort
*/