class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        map<char,int> s1_map;
        map<char,int> s2_map;

        int left = 0;
        int right = 0;

        for(auto& letter : s1){
            s1_map[letter]+=1;
        }

        while(right < s2.size()){

            s2_map[s2[right]]+=1;

            // if window is not equal to length of s1 we enlarge
            if((right-left+1) >= s1.size()){
                // case when we have equal length in s2 and s1
                if(s2_map == s1_map){
                    return true;
                }

                // if not we move map by removing left
                s2_map[s2[left]]--;
                if(s2_map[s2[left]] <= 0){
                    cout << s2[left] << endl;
                    s2_map.erase(s2[left]);
                }
                left++;
            }
            right++;
        }

        return false;
    }
};

// sliding window store sort chars in sorted container 
