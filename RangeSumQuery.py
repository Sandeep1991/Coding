#Question from LeetCode
class NumArray(object):
    def __init__(self, nums):
        """
        initialize your data structure here.
        :type nums: List[int]
        """
        nums = list(nums)
        size = len(nums)
        self.sums = [0] * (size+1)
        for x in range(size):
                self.sums[x+1] = self.sums[x]+nums[x]

       # print self.sums

    def sumRange(self, i, j):
        """
        sum of elements nums[i..j], inclusive.
        :type i: int
        :type j: int
        :rtype: int
        """

        return self.sums[j+1] - self.sums[i]

# Your NumArray object will be instantiated and called as such:
numArray = NumArray([-2, 0, 3, -5, 2, -1])
print numArray.sumRange(2,5)
#numArray.sumRange(1, 2)
