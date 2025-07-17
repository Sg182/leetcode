class Solution(object):
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        stack = []
        element = path.split('/')
        for i in element:
            if (i == '' or i =='.'):
                continue
            if (i == '..'):
                if stack:
                    stack.pop()
            else:
                stack.append(i)
        
        canonical = '/'+ '/'.join(stack)
        return canonical
        

if __name__ == '__main__':

    sol = Solution()
    tests = ["/home/","/home/user/../Pictures"]

    for p in tests:
        print(f"{p} --> {sol.simplifyPath(p)}")

    