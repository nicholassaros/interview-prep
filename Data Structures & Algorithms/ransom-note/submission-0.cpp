class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        

        std::unordered_map<char,int> magazineMap;
        for(const auto& c : magazine) {
            magazineMap[c]++;
        }


        for(const auto& c : ransomNote) {
            if (!magazineMap.contains(c)) {
                return false;
            }

            magazineMap[c]-=1;
            if (magazineMap[c] < 0) { return false; }
        }

        return true;

    }
};


/*

get freq of ransomNote
get freq of magazine

loop over ransome and check if within magazine

*/