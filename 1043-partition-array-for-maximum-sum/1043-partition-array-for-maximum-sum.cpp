class Solution {
public:
//     int f(int i, int n, vector<int> &arr, int k,vector<int> &dp){
//         if(i==n)
//             return 0;
//         if(dp[i]!=-1)
//             return dp[i];
        
//         int ans=INT_MIN;
//         int len=0,maxele=INT_MIN;
//         for(int j=i;j<min(n,k+i);j++){
//            len++;
//             maxele=max(maxele,arr[j]);
//             int sum=len*maxele+f(j+1,n,arr,k,dp);
            
//             ans=max(ans,sum);
//         }
        
//         return dp[i]=ans;
//     }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        // vector<int> dp(n,-1);
        // return f(0,n,arr,k,dp);
        
        vector<int> dp(n+1,0);
        
        for(int i=n-1;i>=0;i--){
            int ans=INT_MIN;
        int len=0,maxele=INT_MIN;
        for(int j=i;j<min(n,k+i);j++){
           len++;
            maxele=max(maxele,arr[j]);
            int sum=len*maxele+dp[j+1];
            
            ans=max(ans,sum);
        }
        
        dp[i]=ans;
        }
        
        return dp[0];
            
        
    }
};