class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        

        for(int i = 0; i<strs[0].size(); i++) {
            for (const auto& word : strs) {
                if (i >= word.size() || strs[0][i] != word[i]) {
                    return strs[0].substr(0,i);
                }
            }
        }

        return strs[0];
    }
};