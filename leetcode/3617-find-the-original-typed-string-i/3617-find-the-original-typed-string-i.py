class Solution:
    def possibleStringCount(self, word: str) -> int:
        possibleVal = 1
        w = ""
        for i in word: 
            if w == i:
                possibleVal +=1
            else:
                w = i

        return possibleVal