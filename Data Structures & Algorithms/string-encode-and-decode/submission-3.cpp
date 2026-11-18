class Solution {
public:

    string encode(vector<string>& strs) {
        std::string response = "";

        for(const auto& s : strs) {
            response += std::to_string(s.size());
            response += '#';
            response += s;
        }

        return response;
    }

    vector<string> decode(string s) {

        vector<string> result;
        
        int right = 0;

        while(right < s.size()) {

            int left = right;

            while(right < s.size() && s[right] != '#') {
                right++;
            }

            int length = stoi(s.substr(left, right-left));

            string word = s.substr(right + 1, length);
            result.push_back(word);

            right = right + 1 + length;
        }

        return result;

    }
};
