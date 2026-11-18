class Solution {
public:

    string encode(vector<string>& strs) {
        std::string res{};

        for(auto& s : strs) {

            res += std::to_string(s.size());
            res += '#';
            res += s;
        }

        return res;

    }

    vector<string> decode(string s) {
        std::cout << s << std::endl;

        int cursor = 0;
        std::vector<std::string> res;

        while(cursor < s.size()) {
            std::string strSize{};

            while(s[cursor] != '#') {
                strSize += s[cursor];
                cursor++;
            }

            cursor++;
            int intSize = stoi(strSize);
            std::string buffer{};

            for(int i = 0; i<intSize; i++) {
                buffer += s[cursor];
                cursor++;
            }

            res.push_back(buffer);
        }

        return res;
    }
};

/*

prefix with a delim and then the length of the string and then a suffix 

*/