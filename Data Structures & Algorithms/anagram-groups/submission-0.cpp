class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        

        map<string,vector<string>> bucket;
        vector<vector<string>> res;

        for(auto& str : strs) {
            string sorted_str = str;
            sort(sorted_str.begin(), sorted_str.end());
            bucket[sorted_str].push_back(str);
        }

        for(auto& [key,value] : bucket) {
            res.push_back(value);
        }

        return res;


    }
};

// sort strings and store in map<string,vector<string>
// place each sorted str in the appropriate bucket
// itterate over map and output to vector