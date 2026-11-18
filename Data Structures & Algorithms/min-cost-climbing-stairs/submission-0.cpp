class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int minCost = min(findMinCost(cost,0), findMinCost(cost,1));
        return minCost;
    }

    int findMinCost(vector<int>& cost, int pos) {
        if (pos >= cost.size()) {
            return 0;
        }

        int moveOne = findMinCost(cost, pos+1) + cost[pos];
        int moveTwo = findMinCost(cost, pos+2) + cost[pos];
        return min(moveOne,moveTwo);
    }
};
