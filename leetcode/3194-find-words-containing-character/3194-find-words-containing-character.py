class Solution:
    def findWordsContaining(self, words: List[str], x: str) -> List[int]:
        res = []
        for i,v in enumerate(words):
            if x in v:
                res.append(i) 

        return res