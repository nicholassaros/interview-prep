class Solution {
public:
    bool wordPattern(string pattern, string s) {
        std::istringstream iss(s);
        std::string word;


        std::unordered_map<char, std::string> charMap;
        std::unordered_map<std::string, char> wordMap;



        std::vector<std::string> vec;

        while(iss >> word) {
            std::cout << word << std::endl;
            vec.push_back(word);
        } 

        if(vec.size() != pattern.size()) { return false;}

        for(int i = 0; i< pattern.size(); i++) {

            // if pattern in charMap && not in wordMapchar
            if(charMap.contains(pattern[i]) && !wordMap.contains(vec[i])) {
                return false;
            } 
            

            // if pattern in charMap && not in wordMapchar
            if(!charMap.contains(pattern[i]) && wordMap.contains(vec[i])) {
                return false;
            } 
            

            // if both not in map
            if(charMap.contains(pattern[i]) 
                && wordMap.contains(vec[i])
                && wordMap[vec[i]] != pattern[i]
                && charMap[pattern[i]] != vec[i]) {
                return false;
            } 

            charMap[pattern[i]] = vec[i];
            wordMap[vec[i]] = pattern[i];
        }

        return true;

        
    }


    /*
        if both in map and not equal
        if one in map and other not
        if one in map and other not
        if neither in map


    */
};


