Approach : Recursion + Memoization (Top-Down) Approach 

class Solution {
    int rec(vector<int> &nums,int index,vector<int> &dp)
    {
        int n = nums.size();
        if(index>=n)
        {
            return 0;
        }
        
        if(dp[index] != -1)
        {
            return dp[index];
        }

    int take = nums[index] + rec(nums,index+2,dp);
    int not_take = rec(nums,index+1,dp);
        
    return dp[index] = max(take,not_take);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,-1);
        int index = 0;
        return rec(nums,0,dp);
    }
};
