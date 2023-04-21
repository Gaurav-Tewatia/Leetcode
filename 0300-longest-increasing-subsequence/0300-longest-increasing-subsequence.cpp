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
    
    
    
//     //this is the code for bottom up approach
//     int solvebottomup(vector<int> &nums, vector<vector<int>> &dp,int n){
        
//         for(int cur=n-1;cur>=0;cur--){
//             for(int prev=cur-1;prev>=-1;prev--){
//                 int take=0;
//                 if(prev==-1 or nums[cur]>nums[prev]) //here we have not donw prev+1 as for prev -1 we are already checking it
//                     take=1+dp[cur+1][cur+1]; //this is done because -1 index is not present in the vector
                
//                 int nottake=dp[cur+1][prev+1];
                
//                 dp[cur][prev+1]=max(take,nottake);
//             }
//         }
        
//         return dp[0][0];
        
//     }
    
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
       // vector<vector<int>> dp(n,vector<int>(n+1,-1));
        
       // return solvemem(nums,0,-1,dp,n);
        
//         vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        
//         return solvebottomup(nums,dp,n);
        
        vector<int> cur(n+1,0),prev(n+1,0);
        
        for(int currow=n-1;currow>=0;currow--){
            for(int prevrow=currow-1;prevrow>=-1;prevrow--){
                int take=0;;
                if(prevrow==-1 or nums[currow]>nums[prevrow])
                    take=1+prev[currow+1];
                
                int nottake=prev[prevrow+1];
                
                cur[prevrow+1]=max(take, nottake);
            }
            prev=cur;
        }
        
        return prev[0];
    }
};