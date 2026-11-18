class Solution {
public:
    string customSortString(string order, string s) {
        
        std::unordered_map<char,int> charMap;
        std::string res = "";


        for(const auto& c : s) {
            charMap[c]++;
        }

        for(const auto& c : order) {
            if(!charMap.contains(c)) {continue; }
            
            for(int i = 0; i<charMap[c]; i++) {
                res+=c;
            }

            charMap.erase(c);
        }

        for(const auto& [c, count] : charMap) {
            
            for(int i = 0; i<count; i++) {
                res+=c;
            }
        }

        return res;
    }
 };


/*

chars in the order take priority over all others

since we can return chars in ay permutation which satisifes order

1. get freq of s
2. Loop over order and return the char freq 
3. remove from freq map
4. loop over remaining elements in freq map and add to result string

*/