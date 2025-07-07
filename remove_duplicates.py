class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        if len(nums) <= 1:
            return len(nums)

        
        ptr = 0

        for i in range(1,len(nums)):     # I have tried to keep space complx O(1)
            if nums[i] != nums[i-1]:
                ptr = ptr+1
                nums[ptr] = nums[i]
                 
            else:
                continue 

        return ptr + 1
    
nums = [1, 1, 2, 2, 3, 4, 4, 5]
sol = Solution()
length = sol.removeDuplicates(nums)
print(length)
