class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int res = 0;
        int left = 0;

        for(int right = 0; right < prices.size(); right++) {

            if(prices[right] < prices[left]) {
                left = right;
            } else {
                res = max(res, prices[right] - prices[left]);
            }
        }

        return res;
    }
};

/*
slide window until we reach local min
we should always use new lowest 


*/
