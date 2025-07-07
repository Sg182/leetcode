'''Given an array of integers nums and an integer target,
 return indices of the two numbers such that they add up to target.'''

def two_sum(nums, target):
    seen = {}                    
    for i, num in enumerate(nums):  
        comp = target - num      
        if comp in seen:        # Have we already seen that complement?
            return [seen[comp], i]
        seen[num] = i           #Otherwise, remember this number’s index
    raise ValueError("No solution")