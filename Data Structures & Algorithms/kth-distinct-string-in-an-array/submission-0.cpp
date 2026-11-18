class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        
        std::unordered_map<string, int> freqMap;

        for(auto& str : arr) {
            freqMap[str]++;
        }


        std::set<string> distinctSet;
        for(auto& [str, freq] : freqMap) {
            if(freq == 1){
                distinctSet.insert(str);
            }
        }

        int distinctCount = 0;
        for(auto& str : arr) {

            if(distinctSet.contains(str)) {
                distinctCount++;

                if(distinctCount == k) {
                    return str;
                }
            }
        }

        return "";
    }
};
