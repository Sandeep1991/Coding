#Question from leetcode
"""
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]

The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

Subscribe to see which companies asked this question
"""
class Solution(object):
    # your code goes here
# your code goes here
    def minimumTotal(self,triangle):
	    n = len(triangle)
	    if n==0:
		    return 0
	    for i in range(0,n):
		    for j in range(0,i+1):
			    if i==0 and j==0:
				    triangle[i][j] = triangle[0][0]
			    elif j==0:
				    triangle[i][j] = triangle[i][j] + triangle[i-1][j]
			    elif j!=i:
				    triangle[i][j] = triangle[i][j] + min(triangle[i-1][j],triangle[i-1][j-1])
			    else:
				    triangle[i][j] = triangle[i][j] + triangle[i-1][j-1]
	    return min(triangle[n-1])

