class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        
        sub_str = {}
        window_len = 0
        str_len = 0
        j = 0

        for i, char in enumerate(s):

            if char in sub_str and sub_str[char] >= j:
                j =  sub_str[char] + 1

            sub_str[char] = i

            window_len = i - j + 1
            str_len = max(str_len, window_len)

        return str_len
        

         



