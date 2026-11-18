class Solution {
public:
    int appendCharacters(string s, string t) {
        


        // we need to maintain order of chars so we cannot just get freq of char
        // we should maintain our current char index on T and then search though S
        // if our chars match, we can increment our search for the next char in S
        // We store our results in a set and then return the len of T - len of SET

        int tIndex = 0;

        for(auto& c : s) {
            if(tIndex < t.size() && c == t[tIndex]) {
                tIndex++;
            }
        }


        return t.size() - tIndex;
    }
};