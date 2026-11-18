struct StackObject {
    int index;
    int currentSum;
};


class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int res = 0;

        std::stack<StackObject> _stack;
        _stack.push(StackObject(0, 0));

        while(!_stack.empty()) {
            StackObject object = _stack.top();
            _stack.pop();

            if(object.index >= nums.size()) {

                if(object.currentSum == target) {
                    res++;
                }
            } else {
                _stack.push(StackObject(object.index+1, object.currentSum + nums[object.index]));
                _stack.push(StackObject(object.index+1, object.currentSum - nums[object.index]));
            }
        }

        return res;
        
    }
};
