class Solution:
    def findLHS(self, nums: List[int]) -> int:
        nums.sort()
        length = 0 
        r = 0 
        l = 0 

        while l < len(nums):
            if nums[l] - nums[r] >1:
                r += 1 
            if nums[l] - nums[r] == 1:
                length = l-r+1
            l+=1
        return length
            