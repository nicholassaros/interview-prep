class Solution {
public:


    std::vector<std::string> split(std::string detail) {

        std::vector<std::string> parts;

        parts.push_back(detail.substr(0,10));
        parts.push_back(detail.substr(10,1));
        parts.push_back(detail.substr(11,2));
        parts.push_back(detail.substr(13,2));

        return parts;
    }


    int countSeniors(vector<string>& details) {

        int count = 0;
        
        for(auto& detail : details) {
            std::vector<std::string> detail_parts = split(detail);
            
            if(stoi(detail_parts[2]) > 60) {
                count++;
            }
        }

        return count;
    }
};