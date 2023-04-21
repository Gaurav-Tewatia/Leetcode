class Solution {
public:
    // this is the top down approach
//     int solvemem(vector<int> &nums, int cur, int prev,vector<vector<int>> & dp, int n){
//         if(cur==n)
//             return 0;
        
//         if(dp[cur][prev+1]!=-1)
//             return dp[cur][prev+1];
        
//         int take=0;
//         if(prev==-1 or nums[cur]>nums[prev])
//             take=1+solvemem(nums,cur+1,cur,dp,n);
        
//         int nottake=solvemem(nums,cur+1,prev,dp,n);
        
//         return dp[cur][prev+1]=max(take,nottake);
//     }
    
    
    int solvebottomup(vector<int> &nums, vector<vector<int>> &dp,int n){
        
        for(int cur=n-1;cur>=0;cur--){
            for(int prev=cur-1;prev>=-1;prev--){
                int take=0;
                if(prev==-1 or nums[cur]>nums[prev])
                    take=1+dp[cur+1][cur+1];
                
                int nottake=dp[cur+1][prev+1];
                
                dp[cur][prev+1]=max(take,nottake);
            }
        }
        
        return dp[0][0];
        
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
       // vector<vector<int>> dp(n,vector<int>(n+1,-1));
        
       // return solvemem(nums,0,-1,dp,n);
        
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        
        return solvebottomup(nums,dp,n);
    }
};