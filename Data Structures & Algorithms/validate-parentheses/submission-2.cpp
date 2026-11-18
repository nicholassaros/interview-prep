class Solution {
public:
    bool isValid(string s) {

        stack<char> myStack;

        // if open we add to stack
        // if closed we try to pop from stack if not match we return false

        map<char,char> openMap = {{'(',')'}, {'{', '}'}, {'[', ']'}};
        map<char,char> closeMap = {{')','('}, {'}', '{'}, {']', '['}};


        for(const auto& par : s){
            if(openMap.find(par) != openMap.end()){
                // we add to stack
                myStack.push(par);
            } else {
                if(myStack.empty()){return false;}
                // we need to pop from stack and check for match
                char stack_par = myStack.top();
                char expected = closeMap[par];

                if(stack_par != expected){
                    return false;
                }
                myStack.pop();
            }
        }

        if(!myStack.empty()){
            return false;
        }
        return true;




        
    }
};


