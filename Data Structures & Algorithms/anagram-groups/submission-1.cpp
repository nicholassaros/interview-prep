class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> myMap;
        vector<vector<string>> finalVector;


        for(auto s : strs) {
            string tempString = s;
            
            sort(tempString.begin(), tempString.end());
            myMap[tempString].push_back(s);
        }

        for(auto [key,value] : myMap) {
            finalVector.push_back(value);
        }
        return finalVector;
    }
};

/*
iterate thru vector
put into hash map [sorted str, vector<str>]

iterate thru hash map
add each value (vector) to a vector

*/