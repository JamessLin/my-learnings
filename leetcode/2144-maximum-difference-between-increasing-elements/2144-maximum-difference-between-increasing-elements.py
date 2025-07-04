class Solution:
    def maximumDifference(self, nums: List[int]) -> int:
        m = len(nums)
        largestVal = -1
        for i in range(m):
            for j in range(i, m): 
                diff = (nums[j] - nums[i])
                if diff > largestVal and diff !=0:
                    largestVal = diff


        return largestVal