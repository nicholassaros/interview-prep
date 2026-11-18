class Solution {
public:
    int findLucky(vector<int>& arr) {

        std::unordered_map<int,int> freqMap;
        int maxLucky = 0;

        for(auto& num : arr) {
            freqMap[num]++;
        }

        for(auto& [key, val] : freqMap) {
            // loops over map
            if(key == val) {
                maxLucky = max(maxLucky, key);
            }
        }

        if (maxLucky == 0) {
            return -1;
        }
        return maxLucky;
    }
};


/*

1. Itterate through arr
2. Count freq in hash map (key = num, val = freq)
3. loop over map, when key,val are equal we update max
4. Store max in an int maxCount


*/