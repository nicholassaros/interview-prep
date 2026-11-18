class Solution {
public:
    int lengthOfLastWord(string s) {
        
        std::string token;
        std::stringstream ss(s);
        
        while(ss >> token) {};

        return token.size();

    }
};