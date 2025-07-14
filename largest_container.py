 
def maxArea(height, brute=False):
        """
        :type height: List[int]
        :rtype: int
        """
        ''' Both with brute force and two-pointer algorithm'''
         
        prev_area = 0.0
        if not brute:
            for i in range(1,len(height)+1):
                for j in range(1,len(height)+1):
                 
                    max_area = min(height[i-1],height[j-1])*abs(i-j)
                    if prev_area <= max_area:
                        prev_area = max_area

            return prev_area
        
        
        if brute:
            L, R = 0, len(height) - 1
            max_area = 0
        
            while L < R:  
                h = min(height[L], height[R])
                area = h * (R - L)
                if area > max_area:
                    max_area = area
            
                if height[L] < height[R]:
                    L += 1
                else:
                    R -= 1
        
            return max_area


height = [0,2,3,6,8,3,5]
print(maxArea(height,brute=True))