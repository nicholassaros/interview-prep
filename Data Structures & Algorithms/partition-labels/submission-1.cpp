class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        std::unordered_map<char,int> charMap;

        for (int i = 0; i < s.size(); i++) {
            charMap[s[i]] = i; // set the char = current index
        }

        int left = 0; int currentMaxWindow = 0;
        vector<int> res{};

        
        for(int right = 0; right < s.size(); right++) {

            char currentChar = s[right];
            currentMaxWindow = max(currentMaxWindow, charMap[currentChar]);


            if (right >= currentMaxWindow) { // if we are last occurance of char
                res.push_back(right - left +1);
                left = right + 1;
            }
        }

        return res;






    }
};


/*
split into as many substrings as possible but ensure that the same letter does
not appear in multiple substrings

xyxxy zbzbb i s l



x: 3
y:

How can we do this programatically?

Brute Force:
    get every possible substring and find correct combination


Implementation
    - Seems like we can somehow use intervals

    - Problem seems to be greedy, we should create new substring whenever possible

    - Track last char position in a hashMap

    - we track the maximum char postion in our window

    - if the current char index == map[currentChar] we split






*/