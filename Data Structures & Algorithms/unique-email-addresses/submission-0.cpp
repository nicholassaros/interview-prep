class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        
        std::set<std::string> emailSet;

        // need to find the number of unique emails
        for(auto& email : emails) {
            int domainStartIndex = email.find('@');
            std::string localName = email.substr(0,domainStartIndex);
            std::string domain = email.substr(domainStartIndex+1);

            std::string cleanedLocalName{};

            for(auto& c : localName) {
                if (c == '+') { break; }
                if(c == '.') { continue; }

                cleanedLocalName += c;
            }

            emailSet.insert(cleanedLocalName + "@" + domain);
        }

        return emailSet.size();
    }
};