class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(!nums.size()) return 0;
        int n, max=0,i,j;
        n = nums.size();
        int lis[n] = {0};
        
        for(i=0;i<n;i++)
        {
            lis[i] = 1;
        }
        for(i=1;i<n;i++)
            for(j=0;j<i;j++)
                if(nums[i] > nums[j] && lis[i]<lis[j]+1)
                    lis[i] = lis[j] + 1;
        for(i=0;i<n;i++)
            if(max < lis[i])
                max = lis[i];
        return max;
    }
};
