class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> groupMap;
        vector<vector<string>> res;

        for(auto& str : strs) {

            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());
            groupMap[sortedStr].push_back(str);
        }

        for(auto [str, group] : groupMap) {
            res.push_back(group);
        }

        return res;


    }
};


/*

loop 
sort str
store in map<sort str,vector<string>
return

*/