class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {

        vector<int> result = nums;
        vector<queue<int>> groups;
        unordered_map<int,int> numToGroupMap;

        // sort array and group all elements which are contigious with limit
        // store as groups of queue
        // map each index to which queue the element is contained in
        // loop over nums and replace elements
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++) {
            if(i == 0 || nums[i] - nums[i-1] > limit) {
                queue<int> q;
                q.push(nums[i]);
                groups.push_back(q);
                numToGroupMap[nums[i]] = groups.size()-1;
            } else {
                groups[groups.size()-1].push(nums[i]);
                numToGroupMap[nums[i]] = groups.size()-1;
            }
        }

        for(int i = 0; i<result.size(); i++) {
            int groupIndex = numToGroupMap[result[i]];

            result[i] = groups[groupIndex].front();
            groups[groupIndex].pop();
        }
        return result;
    }
};
