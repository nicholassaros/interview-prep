class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:


        index = 0
        res = ''

        while index < len(word1) or index < len(word2):
            if index < len(word1):
                res+=(word1[index])

            if index < len(word2):
                res+=(word2[index])

            index+=1

        return res
