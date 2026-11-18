class Solution {
    public int[] twoSum(int[] nums, int target) {
        // store values in hash map

        // itterate over input and check if target-value is in map

        // if so return 

        // else store value in map

        HashMap<Integer, Integer> numsMap = new HashMap<>();

        for(int i = 0; i<nums.length; i++) {
            if(numsMap.containsKey(target-nums[i])){
                return new int[] { numsMap.get(target-nums[i]), i };
            }
            numsMap.put(nums[i],i);
        }
        return new int[] {};
    }
}
