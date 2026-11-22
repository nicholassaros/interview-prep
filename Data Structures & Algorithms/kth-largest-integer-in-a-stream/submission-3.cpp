class KthLargest {
public:

    priority_queue<int, vector<int>, greater<int>> minHeap;
    int maxSize;

    void flushHeap() {
        while(minHeap.size() > maxSize){
            minHeap.pop();
        }
    }

    KthLargest(int k, vector<int>& nums) {
        maxSize = k;

        for(auto num : nums) {
            minHeap.push(num);


            flushHeap();
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        flushHeap();

        return minHeap.top();
    }
};
