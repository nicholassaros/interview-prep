class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        

        // sort intervals by first val

        // iterate over inteval

        // compare two intervals. if overlap, modify current interval to reflect merged

        auto cmp = [](auto a, auto b){
            if(a[0] < b[0]) {
                return true;
            }
            return false;
        };

        sort(intervals.begin(), intervals.end(), cmp);

        vector<vector<int>> res;
        res.push_back(intervals[0]); // push back first interval

        for(int i = 1; i< intervals.size(); i++) {
            auto curInterval = intervals[i];
            auto prevInterval = res[res.size()-1];

            if(curInterval[0] <= prevInterval[1]) {
                // need to merge
                res[res.size()-1][1] = max(curInterval[1], prevInterval[1]);
            } else {
                res.push_back(curInterval);
            }
        }
        return res;
    }
};
