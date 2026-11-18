class Solution {
public:
    struct StackElement {
        int temp;
        int index;

        StackElement(int temp, int index) 
            : temp(temp), index(index) {};
    };

    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        std::stack<StackElement> _stack;
        std::vector<int> res(temperatures.size(), 0);


        for(int i = 0; i< temperatures.size(); i++) {
            int curTemp = temperatures[i];

            // While the stack is not empty and the curr > top element
            while(!_stack.empty() && curTemp > _stack.top().temp) {
                int stackElementIndex = _stack.top().index;
                res[stackElementIndex] = i - stackElementIndex;
                _stack.pop();
            }

            _stack.push(StackElement(curTemp, i));
        }

        return res;
    }
};








/*



*/