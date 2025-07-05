class Solution:
    def maxSubsequence(self, nums: List[int], k: int) -> List[int]:
        min_heap = []
        res = []
        for i in nums:
            if len(min_heap)< k :
                heapq.heappush(min_heap,i)
            else:
                if i> min_heap[0]:
                    heapq.heapreplace(min_heap, i)

        counts = Counter(min_heap)
        for j in nums:
            if counts[j] > 0:
                res.append(j)
                counts[j] -= 1
        return res 