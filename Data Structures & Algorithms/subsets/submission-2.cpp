class Solution {

public:
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> res{};
        findSubsets(0, {}, nums, res);

        return res;
        
    }


    void findSubsets(int index, vector<int> path, vector<int>& nums, vector<vector<int>>& res) {
        if (index == nums.size()) {
            res.push_back(path);
            return;
        }

        findSubsets(index+1, path, nums, res);
        path.push_back(nums[index]);
        findSubsets(index+1, path, nums, res);
    }
};


/*


Solve this recursivly 

base case is when index is == nums.size()




*/
