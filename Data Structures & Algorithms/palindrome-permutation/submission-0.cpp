class Solution {
public:
    bool canPermutePalindrome(string s) {
        std::unordered_map<char,int> charMap;
        bool hasOdd = false;

        for(const auto& c : s) {
            charMap[c]++;
        }

        for(const auto& [c, freq] : charMap) {

            if(freq % 2 != 0) {
                if (hasOdd) {
                    return false;
                }

                hasOdd = true;
            }
        }

        return true;
    }
};
