class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        
        abs_x = abs(x)
        len_x = len(str(x))
        abs_len = len(str(abs_x))

        if (x < -2**(31)) or (x > 2**(31)-1):
            return 0

        if len_x != abs_len:
            x = -1*int(str(abs_x)[::-1])
        
        else:
            x = int(str(abs_x)[::-1])

        if (x < -2**(31)) or (x > 2**(31)-1):
            return 0

        return x
    
if __name__ == '__main__':

    num = 2380
    x = Solution()
    rev = x.reverse(num)
    print(rev)