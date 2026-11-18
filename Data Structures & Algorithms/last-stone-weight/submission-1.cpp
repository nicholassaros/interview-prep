class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        //std::priority_queue<int, std::vector<int>, std::greater<int>> maxHeap;
        std::priority_queue<int> maxHeap;



        // push all stones to the PQ
        for(auto& stone : stones) {
            maxHeap.push(stone);
        }
        

        // pop top 2 stones
        // if stone == then continue
        // if not then add back stone1-stone2
        // loop while the queue size is 1 or empty

        while(maxHeap.size() > 1) {
            int stone1 = maxHeap.top();
            maxHeap.pop();

            int stone2 = maxHeap.top();
            maxHeap.pop();

            if(stone1 == stone2) { continue; }

            maxHeap.push(stone1-stone2);
        }



        if (maxHeap.empty()) { return 0; }
        return maxHeap.top();
    }
};
