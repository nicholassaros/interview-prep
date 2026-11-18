#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> number_stack;

        for (auto& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                // Pop two numbers from the stack
                int second = number_stack.top(); number_stack.pop();
                int first = number_stack.top(); number_stack.pop();

                // Apply the operator
                if (token == "+") {
                    number_stack.push(first + second);
                } else if (token == "-") {
                    number_stack.push(first - second);
                } else if (token == "*") {
                    number_stack.push(first * second);
                } else if (token == "/") {
                    number_stack.push(first / second);  // Integer division
                }
            } else {
                // It's a number, so convert and push to the stack
                number_stack.push(stoi(token));
            }
        }

        // The result will be the top of the stack
        return number_stack.top();
    }
};

