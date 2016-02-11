class Solution(object):
    def isPowerOfThree(self,n):
        """
        :type n: int
        :rtype: bool
        """
        n = int(n)
        while(n%3==0):
            n /= 3
        print n
        if(n==1):
            print True
        else:
            print False

if __name__ == "__main()__":
    s = Solution()
    print Solution.isPowerOfThree("5")
