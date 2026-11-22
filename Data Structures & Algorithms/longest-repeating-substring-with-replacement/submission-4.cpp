class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int left = 0;
        int res = 0;
        int mostFreqChar = 0;

        unordered_map<char,int> charMap;

        for(int right = 0; right < s.size(); right++) {
            charMap[s[right]]++;

            mostFreqChar = max(mostFreqChar, charMap[s[right]]);

            while((right - left+1) - mostFreqChar > k) {
                charMap[s[left]]--;
                left++;
            }



            res = max(res, right-left+1);

        }
        return res;
    }
};


/*

while (right -left +1 ) - most frequent > k

*/