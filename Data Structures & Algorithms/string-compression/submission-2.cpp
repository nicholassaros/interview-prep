class Solution {
public:
    int compress(vector<char>& chars) {

        int left = 0; int freq = 0; int k = chars.size();
        char prevChar = chars[0];

        for(int right = 0; right < chars.size(); right++) {
            
            if (prevChar == chars[right]) {
                // we are counting freq of char
                freq++;
            } else {
               
                std::string writeString;

                writeString += prevChar;
                if (freq > 1) { writeString += std::to_string(freq); }

                std::cout << writeString << std::endl;

                for(const auto& c : writeString) {
                    chars[left] = c;
                    left++;
                }
                
                freq = 1;
            }

            prevChar = chars[right];
        }

        
        std::string writeString;
        writeString += prevChar;
        if (freq > 1) { writeString += std::to_string(freq); }

        for(const auto& c : writeString) {
            chars[left] = c;
            left++;
        }

        return left;
    }
};

/*
// scan over list and build a mapping of char + freq

a a a a b b b b 

*/
