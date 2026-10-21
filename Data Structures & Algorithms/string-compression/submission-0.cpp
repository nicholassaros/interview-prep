class Solution {
public:
    int compress(vector<char>& chars) {
        
        int left = 0;
        int write = 0;

        for(int right = 0; right < chars.size(); right++) {

            // if next char is oob or it is a diff char
            // Calc length
            // write result
            if(right == chars.size()-1 || chars[right] != chars[right+1]) {
                
                string res;
                res += chars[left];
                
                if(right-left+1 > 1) {
                    res += to_string(right-left+1);
                }

                for(auto c : res) {
                    chars[write] = c;
                    write++;
                }

                left = right+1;
            }
        }

        return write;
    }
};