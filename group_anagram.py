from collections import defaultdict
class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """

        buckets = defaultdict(list)

        if len(strs) == 0:
            raise ValueError("should be atleast one charecter")
        if strs == [""]:
             return [[""]]

        for str in strs:
            key = tuple(sorted(str))
            buckets[key].append(str)  #str is the original string

        lst = buckets.values()
        print(lst)
         
        return list(buckets.values())
    
if __name__ == "__main__":

    strs = ["eat","tea","tan","ate","nat","bat"]
    sol = Solution()
    print(sol.groupAnagrams(strs))

        