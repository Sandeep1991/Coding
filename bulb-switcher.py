#O(1) solution for the given problem

class Solution(object):
    def bulbSwitch(self, n):
        """
        :type n: int
        :rtype: int
        """
        
        return int(math.sqrt(n))

# But what if the question was rephrased as to give the exact bulbs that are on/off
"""
def bulbSwitch(n):
    l = [0] * n
    for i in l:
        l[i] = not(l[i])
    cnt = 2
    while cnt < n-1:
        while cnt < n-1:
            l[cnt] = not(l[cnt])
            cnt = cnt * 2
        cnt = cnt + 1
    return l
    
"""
