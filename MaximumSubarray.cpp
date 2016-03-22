/*
53. Maximum Subarray
Total Accepted: 103743 Total Submissions: 285676 Difficulty: Medium

Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6. 
*/
int maxSubArray(vector<int>& nums) {
			if(nums.size() ==0) return 0;
			int curr_max = nums[0];
			int max_so_far = nums[0];
			for(int i=1;i<nums.size();i++)
			{
				curr_max = max(nums[i], curr_max + nums[i]);
				max_so_far = max(max_so_far,curr_max);
			}
			return max_so_far;
