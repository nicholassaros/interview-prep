class Solution {
public:
    int characterReplacement(string s, int k) {
        std::unordered_map<char,int> freqMap;

        int left = 0; int maxFreq = 0; int maxSize = 0;

        for(int right = 0; right < s.size(); right++) {
            char currentChar = s[right];
            freqMap[currentChar]++;

            maxFreq = max(maxFreq, freqMap[currentChar]);

            while((right-left+1) - maxFreq > k) {
                freqMap[s[left]]--;
                left++;
            }

            maxSize = max((right-left+1), maxSize);
        }

        return maxSize;
    }
};


/*

maintain set of letters

add letter

shrink window

record max size


while size - maxFreq > k
*/