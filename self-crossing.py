#https://leetcode.com/problems/self-crossing/
class Solution(object):
    def isSelfCrossing(self, x):
        """
        :type x: List[int]
        :rtype: bool
        """
        n = len(x)
        if n < 4: return False
        t1, (t2, t3, t4) = 0, x[:3]
        increase = True if t2 < t4 else False
        for i in xrange(3, n):
            t5 = x[i]
            if increase and t3 >= t5:
                if t5 + t1 - t3 < 0 or i + 1 < n and x[i + 1] + t2 - t4 < 0:
                    increase = False
                elif i + 1 < n:
                    return True
            elif not increase and t3 <= t5:
                return True
            t1, t2, t3, t4 = t2, t3, t4, t5
        return False
