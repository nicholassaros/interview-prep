class Solution {
public:
    int maxNumberOfBalloons(string text) {
        
        
        int res = 0;
        std::unordered_map<char, int> balloonMap = {
            {'b', 1}, 
            {'a', 1}, 
            {'l', 2}, 
            {'o', 2}, 
            {'n', 1}
        };
        std::unordered_map<char, int> freqMap;

        for(const auto& c : text) {
            if (balloonMap.contains(c)) {
                freqMap[c]++;
            }
        }


        while(true) {

            for(auto [c, count] : balloonMap){
                freqMap[c]-=count;

                if (freqMap[c] < 0) {
                    return res;
                }
            }
            res++;
        }

        return res;
    }
};