class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        std::unordered_map<char,int> charMap;
        std::vector<int> res;

        for(int i = 0; i<s.size(); i++) {
            charMap[s[i]] = i; // Records last index for each char
        }

        int indexToSplit = 0;
        std::string currentString = "";

        for (int i = 0; i<s.size(); i++) {
            currentString += s[i];
            indexToSplit = max(indexToSplit, charMap[s[i]]);

            if (i == indexToSplit) {
                res.push_back(currentString.size());
                currentString = "";
                indexToSplit = i;
            }
        }

        return res;
    }
};

/*
Maybe represent as intervals for each char (first index, last index)

aabaabccccc

1. Represent chars as interval with last index position
map<char,index>

2. How to tell if we can split?
    - Walk string
    - Track index to split as max (last char index)
    - Capture current index and char
    - If current index = index to split we split
    - Reset index to split


*/
