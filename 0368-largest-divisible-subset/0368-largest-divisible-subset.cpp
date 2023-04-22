class Solution {
public:
//     int solve(vector<int> & nums, int cur, int prev, int n ,vector<vector<int>> &dp){
//         if(cur==n)
//             return 0;
        
//         if(dp[cur][prev]!=-1)
//             return dp[cur][prev];
        
//         if(nums[cur]%nums[prev]==0 or nums[prev]%nums[cur]==0){
            
//         }
//     }
   
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),end(nums));
         vector<int> dp(n,1),hash(n,0);
            int lastindex=0;
            int maxi=0;
            for(int i=0;i<n;i++){
                hash[i]=i;
                for(int prev=0;prev<i;prev++){
                    if(nums[i]%nums[prev]==0 and 1+dp[prev]>dp[i]){
                        hash[i]=prev;
                        dp[i]=1+dp[i];
                        
                        
                    }
                }
                if(dp[i]>maxi){
                    maxi=dp[i];
                    lastindex=i;
                }
                
            }
            vector<int> ans;
            ans.push_back(nums[lastindex]);
            while(hash[lastindex]!=lastindex){
                
                lastindex=hash[lastindex];
                
                ans.push_back(nums[lastindex]);
            }
            
            reverse(begin(ans),end(ans));
            
            return ans;
         
     
    }
};