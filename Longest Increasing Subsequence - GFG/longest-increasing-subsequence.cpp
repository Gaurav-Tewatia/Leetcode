//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    
    //top down approach;
    // int solvemem(int *a,int n,int cur,int prev,vector<vector<int>>& dp){
    //     if(cur==n)
    //     return 0;
        
    //     if(dp[cur][prev+1]!=-1)
    //     return dp[cur][prev+1];
        
    //     int take=0;
    //     if(prev==-1 or a[cur]>a[prev])
    //     take=1+solvemem(a,n,cur+1,cur,dp);
        
    //     int nottake=solvemem(a,n,cur+1,prev,dp);
        
    //     return dp[cur][prev+1]=max(take,nottake);
    // }
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
 {   //vector<vector<int>> dp(n,vector<int>(n+1,-1));
    //   return solvemem(a,n,0,-1,dp);
    
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    
    for(int cur=n-1;cur>=0;cur--){
        for(int prev=cur-1;prev>=-1;prev--){
            int take=0;
            if(prev==-1 or a[cur]>a[prev])
            take=1+dp[cur+1][cur+1];
            
            int nottake=dp[cur+1][prev+1];
            
            dp[cur][prev+1]=max(take,nottake);
        }
    }
    
    return dp[0][0];
    
    
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends