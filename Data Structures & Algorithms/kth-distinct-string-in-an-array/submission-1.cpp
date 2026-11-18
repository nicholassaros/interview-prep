class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        std::set<std::string> _distSet;
        std::set<std::string> _seenSet;

        for(auto& str : arr) {
            
            if(_seenSet.contains(str)) { 
                _distSet.erase(str);
            } else {
                _distSet.insert(str);
                _seenSet.insert(str);
            }
        }

        int distCount = 0;
        for(auto& str : arr) {
            if(_distSet.contains(str)) {
                distCount++;

                if(distCount == k) { return str;}
            }

        }
        return "";
    }
};