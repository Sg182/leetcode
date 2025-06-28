'''
=========================================================================================
Given an integer array nums, return true if any value appears more than once in the array, 
    otherwise return false.

====================================================================
'''
from typing import List

class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:

        if len(nums) < 2:
            return False
        
        
        nums.sort()
        prev = nums[0]
        
        for i in range(1,len(nums)):
            if nums[i] != prev:
                prev = nums[i]
                continue
            else:
                return True
                 
        return False    

if __name__ == "__main__":

    num = [2,4,3,2,6]
    num_f = [1,2,4,7,3,5]

    sol = Solution()

    print(sol.hasDuplicate(num))
    print(sol.hasDuplicate(num_f))


