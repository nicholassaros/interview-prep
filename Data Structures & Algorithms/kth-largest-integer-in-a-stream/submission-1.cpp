class KthLargest {
public:
    std::priority_queue<int, vector<int>, greater<int>> pq;
    int k;


    KthLargest(int k, vector<int>& nums) 
        : k(k) {
        
        for(auto& num : nums) {
            pq.push(num);
            if(pq.size() > k) {
                pq.pop();
            }
        }
    }
    
    int add(int val) {

        pq.push(val);
        if (pq.size() > k) {
            pq.pop();
        }

        return pq.top();

    }
};
