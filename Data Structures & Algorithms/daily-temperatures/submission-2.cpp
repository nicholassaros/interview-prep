class Solution {
public:
    struct StackPair {
        int index;
        int temp;
    };

    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        std::stack<StackPair> _stack;
        std::vector<int> result(temperatures.size());

        for(int i = 0; i<temperatures.size(); i++) {
            // check if we can process from stack

            while(!_stack.empty() && temperatures[i] > _stack.top().temp) {
                auto sp = _stack.top();
                _stack.pop();

                result[sp.index] = i - sp.index;
            }

            _stack.push(StackPair{i,temperatures[i]});
        }

        return result;


    }
};



/*


[30,38,30,36,35,40,28]
  1, 0, 1, 


35
36
38








*/