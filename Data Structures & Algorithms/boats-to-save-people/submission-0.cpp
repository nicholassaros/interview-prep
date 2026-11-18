class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        // sort and use two pointers

        sort(people.begin(), people.end());

        int left = 0;
        int right = people.size()-1;
        int res= 0;

        while(left <= right){
            if (people[left] + people[right] <= limit){
                left+=1;
                right-=1;
            } else {
                right-=1;
            }
            res++;
        }
        return res;
    }
};