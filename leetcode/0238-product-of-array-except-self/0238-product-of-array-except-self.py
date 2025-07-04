class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        res = [1] * n  
        
        products = 1
        zeroes = 0
        
        for i in nums:
            if i == 0:
                zeroes += 1
            else:
                products *= i
       
        if zeroes > 1:
            return [0] * n  
        elif zeroes == 1:
            for j in range(n):
                if nums[j] == 0:
                    res[j] = products
                else:
                    res[j] = 0
        else:
            for k in range(n):
                res[k] = products // nums[k]
        
        return res
