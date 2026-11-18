class Solution {
public:
    int characterReplacement(string s, int k) {


        map<char,int> count_map;
        int max_freq = 0;
        int left = 0;
        int res = 0;


        for(int right = 0; right<s.size(); right++){
            // add right to map and check if new higest freq
            count_map[s[right]]++;
            max_freq = max(max_freq, count_map[s[right]]);

            // while window - max freq is larger than k we want to subtract
            while((right-left+1) - max_freq > k){
                count_map[s[left]]--;
                left++;
            }
            res = max(res, right - left + 1);

        }

        return res;
        
    }
};
