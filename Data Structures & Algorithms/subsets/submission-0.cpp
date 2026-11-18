class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        stack<pair<int,vector<int>>> Stack;
        vector<vector<int>> res;

        vector<int> init_path;

        Stack.push(make_pair(0,init_path));

        while(!Stack.empty()){

            pair<int,vector<int>> tuple = Stack.top();
            Stack.pop();

            int index = tuple.first;
            vector<int> path = tuple.second;

            if(index >= nums.size()){
                res.push_back(path);
            } else {

                Stack.push(make_pair(index+1, path));

                path.push_back(nums[index]);
                Stack.push(make_pair(index+1, path));
            }
        }

        return res;
    }
};

// two choices are to add and not to add
