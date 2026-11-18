class Solution {
public:
    string customSortString(string order, string s) {

        std::unordered_map<char,int> charMap;

        std::string res;

        for (const auto& character : s) {
            charMap[character]++;
        }

        for (const auto& c : order) {

            if (!charMap.contains(c)) {
                continue;
            }
            
            for (int i = 0; i < charMap[c]; i++) {
                res.push_back(c);
            }
            charMap.erase(c);
        }


        for (const auto& [c, freq] : charMap) {

            for(int i = 0; i<freq; i++) {
                res.push_back(c);
            }
        }

        return res;


    }
};



/*
    we need to find the character ordering in order and 
    chage the string s to match this ordering

    - Guarantee: order string has only unique chars 

    - I dont think we use window or two pointers

    - How do we permutate the other string?
        - Save the char frequency in a MAP and build it based on the ordering

    
    -- Implementation
        - Iterate over s and save freq of each character
        - Itterate over order and build result based on current char





*/