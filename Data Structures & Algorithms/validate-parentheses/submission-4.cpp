class Solution {
public:
    bool isValid(string s) {

        stack<char> _stack;

        unordered_map<char,char> openMap = {
            {'(' , ')'},
            {'{' , '}'},
            {'[' , ']'}
        };


        for(auto& c : s) {
            if(openMap.contains(c)) {
                _stack.push(c);
            } else {

                if(_stack.empty() || openMap[_stack.top()] != c) {
                    return false;
                }

                _stack.pop();
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

if not open, pop from stack

*/