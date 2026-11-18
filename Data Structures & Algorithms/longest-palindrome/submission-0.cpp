class Solution {
public:
    int longestPalindrome(string s) {

        std::map<char,int> freqMap;
        int res = 0;
        bool isAddedOdd = false;

        for(auto& letter : s) {
            freqMap[letter]++;
        }


        //loop over map
        for(auto& [key, value] : freqMap) {

            // if our value is odd and we have not added the odd value 
            if(value % 2 != 0 && isAddedOdd == false) {
                res+=value;
                isAddedOdd = true;
            } else if(value % 2 != 0 && isAddedOdd == true) {
                res+=value-1;
            } else {
                res+=value;
            }
        }

        return res;
        
    }
};

/*
Letters are case sensative so we have to treat upper and lower different 
To form a palindrome we have to mirror letters



"abccccdd"
"dccaccd"

c: 4
b: 3
a: 1


add all even numbers
track boolean for odd value
if we have not seen odd we can add and continue otherwise we subtrack 1


*/


