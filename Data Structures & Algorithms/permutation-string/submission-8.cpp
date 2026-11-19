class Solution {
public:
    bool checkInclusion(string s1, string s2) {


        unordered_map<char, int> s1Map;
        unordered_map<char, int> s2Map;

        for(auto& c : s1) {
            s1Map[c]++;
        }

        int left = 0;
        for(int right = 0; right < s2.size(); right++) {
            s2Map[s2[right]]++;
            
            while (right - left + 1 > s1.size()) {
                s2Map[s2[left]]--;
                if (s2Map[s2[left]] == 0) {
                    s2Map.erase(s2[left]);
                }
                left++;
            }

            if(s1Map == s2Map) {
                return true;
            }
        }

        return false;


    
        
    }
};
