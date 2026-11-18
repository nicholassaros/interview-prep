class Solution {
public:
    int firstUniqChar(string s) {

        std::unordered_map<char, int> uniqueMap;
        int res = s.size();

        for(int i = 0; i<s.size(); i++) {
            if(!uniqueMap.contains(s[i])) {
                uniqueMap[s[i]] = i;
            } else {
                uniqueMap[s[i]] = s.size();
            }
        }

        for(auto& [c, index] : uniqueMap) {
            res = min(res, index);
        }

        if(res == s.size()) {
            return -1;
        }
        return res;



        
    }
};


// store char in a map
// if char not in map add char,index
// if char in map set to -1
// return min in map