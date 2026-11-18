class MinStack {
public:

    struct Node {
        int nodeVal;
    };

    list<Node> nodeList;
    stack<list<Node>::iterator> _stack;

    MinStack() {

    }
    
    void push(int val) {
        
        for(auto it = nodeList.begin(); it != nodeList.end(); it++) {
            if(val < it->nodeVal) {
               _stack.push(nodeList.emplace(it, val));
               return;
            }
        }
        _stack.push(nodeList.emplace(nodeList.end(), val));
    }
    
    void pop() {
        auto it = _stack.top();
        _stack.pop();

        nodeList.erase(it);
    }
    
    int top() {
        auto it = _stack.top();
        return it->nodeVal;
    }
    
    int getMin() {
        return nodeList.begin()->nodeVal;
    }
};
