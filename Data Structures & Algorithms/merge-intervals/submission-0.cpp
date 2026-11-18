class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;

        for(auto& interval : intervals){
            if(res.empty()){
                res.push_back(interval);
            } else if(interval[0] <= res[res.size()-1][1]) {
                cout << "Attempting merge" << endl;
                res[res.size()-1][1] = max(res[res.size()-1][1], interval[1]);
            } else {
                res.push_back(interval);
            }
        }
        return res;
    }
};
// sort vector on index1 and then index2