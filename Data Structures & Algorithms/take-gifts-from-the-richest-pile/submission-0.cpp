class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        
        std::priority_queue<int> heap;
        long long res = 0;

        for(auto& gift : gifts) {
            heap.push(gift);
        }

        for(int i = 0; i<k; i++) {
            int gift = heap.top();
            heap.pop();

            int newGift = std::floor(std::sqrt(gift));
            heap.push(newGift);
        }

        while (!heap.empty()) {
            res += heap.top();
            heap.pop();
        }

        return res;



    }
};


// Push all gifts to the heap
// Loop K times
// Each loop pop from top of heap
// Sqrt element and add back to heap
// after loop loop over all elements in heap and sum