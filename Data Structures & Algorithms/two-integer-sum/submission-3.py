class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        
        numsMap = {}

        for i in range(len(nums)):
            complement = target - nums[i]

            if complement in numsMap:
                return [numsMap[complement], i]
            
            numsMap[nums[i]] = i
        return [0,0]


        