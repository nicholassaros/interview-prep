class Solution {

public:
    struct StackElement {
        std::string str;
        int openCount;
        int closeCount;
    };

    vector<string> generateParenthesis(int n) {
        
        std::vector<std::string> res;
        std::stack<StackElement> _stack;

        _stack.push(StackElement("", n, n));

        while(!_stack.empty()) {

            StackElement elem = _stack.top();
            _stack.pop();

            if(elem.openCount <= 0 && elem.closeCount <= 0) {
                res.push_back(elem.str);
            } else {

                if(elem.openCount > 0) {
                    _stack.push(StackElement(elem.str+"(", elem.openCount-1, elem.closeCount));
                }

                if(elem.openCount < elem.closeCount && elem.closeCount > 0) {
                    _stack.push(StackElement(elem.str+")", elem.openCount, elem.closeCount-1));
                }

            }
        }

        return res;
    }
};

/*


I can add an open or I can add a close
open = 3 close = 3

1. I can always add an open
2. I can add a close if close count > open count





*/
