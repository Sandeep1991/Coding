//Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

//Note: You can only move either down or right at any point in time.
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size()==0) return 0;
        int m = grid.size();
        int n = grid[0].size();
        
        int i,j;
        int tc[m][n] = {};
        tc[0][0] = grid[0][0];
        for(i=1;i<m;i++)
            tc[i][0] = tc[i-1][0] + grid[i][0];
        for(j=1;j<n;j++)
            tc[0][j] = tc[0][j-1] + grid[0][j];
        for(i=1;i<m;i++)
        {
            for(j=1;j<n;j++)
            {
                tc[i][j] = min(tc[i-1][j],tc[i][j-1])+grid[i][j];
            }
        }
        return tc[m-1][n-1];
    }
};
