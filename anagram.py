
'''Given two strings s and t, return true if the two strings are anagrams of each other, otherwise return false.

An anagram is a string that containsthe exact 
same characters as another string, but the order of the characters can be different.'''


from typing import List

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        
        if len(s) != len(t):
            return False

        #for prev_s,prev_t in zip(sorted(s),sorted(t)):
        #   if prev_s != prev_t:
        #       return False
            
        if sorted(t)!=sorted(s):
            return False
        
        return True
 
    

sol = Solution()
test_cases = [("anagram", "nagaram"),("rat", "car"),("listen", "silent"),
    ("hello", "bello"),
]

for s,t in test_cases:
    print(f"{s, t} -> {sol.isAnagram(s,t)}")

         