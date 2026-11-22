class Solution {
public:

    struct StackElement {
        int index;
        vector<int> res;
    };
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> result;


        stack<StackElement> _stack;
        _stack.push(StackElement(0,{}));

        while(!_stack.empty()) {

            StackElement node = _stack.top();
            _stack.pop();

            if(node.index >= nums.size()) {
                result.push_back(node.res);
                continue;
            }

            _stack.push(StackElement(node.index+1,node.res));

            node.res.push_back(nums[node.index]);
            _stack.push(StackElement(node.index+1,node.res));
        }

        return result;
    }
};

