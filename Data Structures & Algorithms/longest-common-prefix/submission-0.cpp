class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        sort(strs.begin(), strs.end());

        string shortest = strs[0];

        string res = "";

        for(size_t i = 0; i<shortest.size(); i++) {
            for (auto& word : strs) {

                if (shortest[i] != word[i]) {
                    return res;
                }

            }

            res+=shortest[i];
        }

        return res;
    }
};