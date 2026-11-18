class Solution:
    def getConcatenation(self, nums: List[int]) -> List[int]:
        res = []

        for num in nums:
            res.append(num)

        for num in nums:
            res.append(num)

        return res