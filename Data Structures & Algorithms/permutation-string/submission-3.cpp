class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        std::unordered_map<char,int> s1_map;

        for(const auto& c : s1) {
            s1_map[c]++;
        }

        for(int i = 0; i<s2.size(); i++) {
            std::unordered_map<char,int> s2_map;
            for(int j = i; j<s2.size(); j++){
                s2_map[s2[j]]++;

                if(s1_map == s2_map) {
                    return true;
                }
            }
        }
        return false;
    }
};
