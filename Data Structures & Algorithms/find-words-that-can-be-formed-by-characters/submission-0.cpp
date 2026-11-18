class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        

        std::unordered_map<char,int> charMap;
        int res = 0;

        for(const auto& c : chars) {
            charMap[c]++;
        }


        for(auto& word : words) {

            std::unordered_map<char,int> goodWordMap = charMap;

            int right = 0;
            while(right < word.size()) {

                if(!goodWordMap.contains(word[right])) {
                    break;
                }
                goodWordMap[word[right]]--;
                if(goodWordMap[word[right]] <= 0) {
                    goodWordMap.erase(word[right]);
                }

                right++;
            }

            if(right == word.size()) {
                res+=word.size();
            }
        }

        return res;

    }
};