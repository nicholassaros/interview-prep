class MinStack {

    stack<int>      m_stack;
    map<int,int>    m_minMap;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        m_stack.push(val);
        m_minMap[val]++;
    }
    
    void pop() {
        int top = m_stack.top();
        if (m_minMap[top] <= 1){
            m_minMap.erase(m_minMap.find(top));
        } else {
            m_minMap[top]--;
        }

        m_stack.pop();
    }
    
    int top() {
        return m_stack.top();
    }
    
    int getMin() {
        auto it = m_minMap.begin();
        return it->first;
    }
};
