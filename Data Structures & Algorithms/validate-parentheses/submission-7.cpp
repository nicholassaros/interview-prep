class Solution {
public:
    bool isValid(string s) {
        
        stack<int> _stack;

        unordered_map<char,char> openMap = {
            {'(' , ')'},
            {'{' , '}'},
            {'[' , ']'}
        };

        for(auto par : s) {
            if(openMap.contains(par)) {
                _stack.push(par);
            } else {
                
                if(!_stack.empty() && openMap[_stack.top()] == par) {
                    _stack.pop();
                } else {
                    return false;
                }
            }
        }

        if(!_stack.empty()) {
            return false;
        }
        return true;

    }
};

/*

if open push to stack
if closed pop from stack
if not match then we have issue


*/
