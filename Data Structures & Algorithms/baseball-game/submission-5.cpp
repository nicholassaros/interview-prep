class Solution {
public:
    int calPoints(vector<string>& operations) {
        

        stack<int> _stack;

        for(auto op : operations) {
            if(op == "+") {
                int stackTop = _stack.top();
                _stack.pop();

                int newTop = stackTop + _stack.top();

                _stack.push(stackTop);
                _stack.push(newTop);
                
            } else if(op == "D") {
                _stack.push(2 * _stack.top());
            } else if(op == "C") {
                _stack.pop();
            } else {
                _stack.push(stoi(op));
            }
        }

        int res = 0;
        while(!_stack.empty()) {
            res += _stack.top();
            _stack.pop();
        }

        return res;
    }
};