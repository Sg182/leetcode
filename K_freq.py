'''Given an integer array nums and an integer k, return the k most frequent elements within the array.'''

from typing import List

 
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        if len(nums)<k:
            print("Not a valid list")

        def key_from_value(arr,target):
            for key,value in arr.items():
                if value == target:
                    return key
            raise ValueError(f"Key {target} not found")

        nums.sort()

        freq = {}
        indx = []
        result = []
        

        for i in nums:
            freq[i] = freq.get(i,0)+1

        for num,no_times in freq.items():
            indx.append(no_times)

        indx.sort(reverse=True)

        for j in indx:
            if len(result) ==k:
                break
            else:
                result.append(key_from_value(freq,j))

        return result


if __name__ == "__main__":
    nums = [1,1,1,2,2,3,3,7,7,3,7,7,3,3,4]
    k = 3
    res = Solution()
    print(res.topKFrequent(nums, k))  # e.g. [3, 1]





        