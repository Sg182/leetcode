class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        length = len(nums)
        
        L = 0
        R = length-1

        while L <= R:
            mid = (L+R)//2
            if nums[mid] == target:
                return mid
            
            if nums[L] < nums[mid]:
                #Then the L sector is sorted and the target is within this sector
                if nums[L] <= target < nums[mid]:
                    R = mid -1
                else:
                    L = mid + 1


            else:
                #  right half [mid..R] is sorted
                if nums[mid] < target <=nums[R]:
                    L = mid + 1
                else:
                    R = mid -1 

        return -1
            
if __name__ == "__main__":

    sol = Solution()

    nums = [4,5,6,7,0,1,2]
    target = 3

    indx = sol.search(nums,target)
    print(indx)
                
                 


                 