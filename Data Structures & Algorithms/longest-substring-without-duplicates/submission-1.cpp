class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        


        std::set<char> charSet;

        int left = 0; int maxLen = 0;


        for(int right = 0; right < s.size(); right++) {


            while(charSet.contains(s[right])) {
                charSet.erase(s[left]);
                left++;
            }

            charSet.insert(s[right]);
            maxLen = max(maxLen, right-left+1);
        }

        return maxLen;
    }
};

/*

sliding window. 

we keep a set of chars. and a left + right ptr

we expand right while the right char is not in the set

*/
