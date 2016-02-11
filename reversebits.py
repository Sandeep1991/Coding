class Solution(object):
    def reverseBits(self, n):
        """
        :type n: int
        :rtype: int
        """
        return int('{:032b}'.format(n)[::-1], 2)

#Step wise alternative method
        #b = '{:032b}'.format(n)
        #c = b[::-1]
        #return int(c,2)
