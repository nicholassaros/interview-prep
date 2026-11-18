class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        

        priority_queue<int> pq;

        for(auto& stone : stones){
            pq.push(stone);
        }

        while(pq.size() >= 2){

            int stone1 = pq.top();
            pq.pop();

            int stone2 = pq.top();
            pq.pop();

            if(stone1 != stone2){
                pq.push(stone1-stone2);
            }
        }

        if(pq.empty()){
            return 0;
        }

        return pq.top();
    }
};

// use priority queue 
// while the size of the queue is 2 or greater take first 2 elements and compute operation
