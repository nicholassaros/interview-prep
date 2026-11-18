#include <cctype> 

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> _stack;

        for(auto token : tokens) {
            if(token == "+" || token == "/" || token == "*" || token == "-") {
                int rhs = _stack.top(); _stack.pop();   // right-hand side
                int lhs = _stack.top(); _stack.pop();   // left-hand side

                if (token == "+")      _stack.push(lhs + rhs);
                else if (token == "-") _stack.push(lhs - rhs);
                else if (token == "*") _stack.push(lhs * rhs);
                else                   _stack.push(lhs / rhs); // division also uses lhs / rhs

            } else {
                _stack.push(std::stoi(token));
            }
        }
        return _stack.top();
    }
};

// loop over tokens IF number then push to stack

// if operator then pop elements from stack and eval

// push result back to stack

// end of loop, return result in the stack


