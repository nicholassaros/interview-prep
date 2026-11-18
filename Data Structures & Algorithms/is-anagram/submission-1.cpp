class Solution {
public:
    bool isAnagram(string s, string t) {

        // count freq of all letters in the string


        std::unordered_map<char,int> charMap;

        for(auto c : s) {
            charMap[c]+=1;
        }



        for(auto c : t) {
            if (charMap.find(c) == charMap.end()) {
                return false;
            }

            charMap[c]-=1;

            if (charMap[c] == 0) {
                charMap.erase(c);
            }
        }

        if(charMap.size() != 0 ) {
            return false;
        }

        return true;

    }
};
