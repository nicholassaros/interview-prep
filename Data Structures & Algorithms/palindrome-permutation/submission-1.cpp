class Solution {
public:
    bool canPermutePalindrome(string s) {
        std::unordered_set<char> charSet;

        for(const auto& c : s) {
            if (!charSet.contains(c)) {
                charSet.insert(c);
            } else {
                charSet.erase(c);
            }
        }

        if (charSet.size() > 1){
            return false;
        }

        return true;
    }
};
