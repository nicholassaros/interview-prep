class Solution {
public:

    bool isSubstring(std::string word, std::string sub) {

        if(word.size() < sub.size()) { return false; }

        for(int index = 0; index<word.size(); index++) {
            int subIndex = 0;

            while(index < word.size() && subIndex < sub.size() && word[index] == sub[subIndex]) {
                index++;
                subIndex++;
            }

            if(subIndex == sub.size()) {
                return true;
            }
        }

        return false;
    }

    vector<string> stringMatching(vector<string>& words) {

        std::vector<std::string> res;
        std::set<std::string> wordSet;

        
        for(int i = 0; i<words.size(); i++) {
            for(int j = 0; j<words.size(); j++) {
                if(i == j) { continue; }

                if(!wordSet.contains(words[j]) && isSubstring(words[i], words[j])) {
                    res.push_back(words[j]);
                    wordSet.insert(words[j]);
                }

            }
        }

        return res;
    }
};


// Double loop over all words
// If current word is larger than comparason word dont check
// if not try to find substring