class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        
        int res = 0;
        int customerCount = 0;
        int maxGrumpyWindow = 0;
        int grumpyWindow = 0;



        int left = 0;
        for(int right = 0; right < customers.size(); right++) {
            if (grumpy[right] == 0) {
                customerCount+=customers[right];
            }

            if(grumpy[right] == 1) {
                grumpyWindow+=customers[right];
            }

            while(right-left +1 > minutes) {
                if(grumpy[left] == 1) {
                    grumpyWindow-=customers[left];
                }
                left++;
            }

            maxGrumpyWindow = max(maxGrumpyWindow, grumpyWindow);
        }

        return customerCount+maxGrumpyWindow;


    }
};


/*
Loop over arr and find all free customers (already not grumpy)
Slide window from start using left and right. 
Only track the increase in customers on grump spaces
    - if under the window size we move right 
    - if over window size we move left as well
*/