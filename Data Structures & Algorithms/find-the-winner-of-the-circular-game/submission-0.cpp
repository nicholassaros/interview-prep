class Solution {
public:
    int findTheWinner(int n, int k) {

        deque<int> _deque;

        for(int i = 1; i < n+1; i++) {
            _deque.push_back(i);
        }

        while(_deque.size() > 1) {
            for(int i = 0; i < k-1; i++) {
                auto num = _deque.front();
                _deque.pop_front();
                _deque.push_back(num);
            }
            _deque.pop_front();
        }
        return _deque.front();
    }
};
