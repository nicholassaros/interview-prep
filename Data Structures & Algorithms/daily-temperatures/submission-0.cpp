
class StackPair {
    public:
    int temp;
    int index;

    StackPair(int _temp, int _index)
        :temp(_temp), index(_index){}
};

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        stack<StackPair> stack;
        vector<int> res(temperatures.size(), 0);
        
        // will store stack_pair which has the temp and the index
        // itterate over temperatures and pop from stack 
        for(int i = 0; i< temperatures.size(); i++){

            StackPair current_pair = StackPair(temperatures[i], i);

            if (stack.empty()){
                stack.push(current_pair);
            } else {
                while (
                    !stack.empty() && 
                    current_pair.temp > stack.top().temp 
                ){
                    res[stack.top().index] = current_pair.index - stack.top().index;
                    stack.pop();
                }
                stack.push(current_pair);
            }


        }
        return res;

    }
};



//
// 30, index
// stack

