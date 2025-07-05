class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        d = {}
        res = []

        for i in nums:
            if i not in d:
                d[i] = 1
            else:
                d[i] += 1

        items = []
        for key in d:
            items.append((key, d[key]))  
      
        for i in range(len(items)):
            for j in range(i + 1, len(items)):
                if items[j][1] > items[i][1]: 
                    items[i], items[j] = items[j], items[i]  

        for i in range(k):
            res.append(items[i][0])  

        return res