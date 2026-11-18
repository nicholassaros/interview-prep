class Solution {
public:

    struct Data {
        vector<int> subset;
        int         index;
    };

    std::stack<Data> _stack;
    vector<vector<int>> subsets(vector<int>& nums) {

        _stack.push(Data({}, 0));
        vector<vector<int>> res;
        
        while(!_stack.empty()) {
            auto data = _stack.top();
            _stack.pop();

            if (data.index >= nums.size()) {
                res.push_back(data.subset);
            } else {
                _stack.push(Data(data.subset, data.index+1));
                data.subset.push_back(nums[data.index]);
                _stack.push(Data(data.subset, data.index+1));
            }
        }
        return res;
    }
};

/*

    We can solve itterativly with a stack

    We 


*/
