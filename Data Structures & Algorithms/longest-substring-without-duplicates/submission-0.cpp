class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::set<char> charSet{};
        int maxLength = 0;

        int left = 0;
        for(int right = 0; right < s.size(); right++) {

            while (charSet.find(s[right]) != charSet.end()) {
                charSet.erase(s[left]);
                left+=1;
            }

            charSet.insert(s[right]);
            maxLength = max(maxLength, right - left + 1);

        }

        return maxLength;
    }
};



// loop over string using sliding window
// track each char in a set
// if the char is alread in the set we need to remove it
