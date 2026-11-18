class Solution {
public:
    string encode(vector<string>& strs) {
        std::string response = "";

        for (const auto& s : strs) {
            response += "#";
            response += std::to_string(s.size());
            response += "-";
            response += s;
        }

        return response;
    }

    vector<string> decode(string s) {
        std::vector<std::string> result;
        int right = 0;

        while (right < s.size()) {
            // skip '#'
            right++;

            std::string stringLength = "";

            while (right < s.size() && s[right] != '-') {
                stringLength += s[right];
                right++;
            }

            int length = std::stoi(stringLength);

            // skip '-'
            right++;

            std::string word = s.substr(right, length);
            result.push_back(word);

            right += length;
        }

        return result;
    }
};