class Solution {
public:
    int firstUniqChar(string s) {
        
        std::unordered_map<char,int> freqMap;

        for(const auto& c : s) {
            freqMap[c]++;
        }


        for (int i = 0; i<s.size(); i++) {
            if(freqMap[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};