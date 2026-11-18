class Solution {
public:
    int characterReplacement(string s, int k) {
        


        std::map<char,int> freqMap;

        int left = 0;
        int maxFreq = 0;

        int res = 0;



        for(int right = 0; right < s.size(); right++) {

            freqMap[s[right]]++; // adds to map

            maxFreq = max(maxFreq, freqMap[s[right]]);
            while((right - left +1) - maxFreq > k) {

                freqMap[s[left]]--;
                maxFreq = max(maxFreq, freqMap[s[left]]);
                left++;

            }

            res = max(right - left +1, res);
        }

        return res;


    }
};


/*

  L   L   R
A A A B A B B


A: 3
B: 2


expanding condition

while (size of window - most frequent char) <= k


*/