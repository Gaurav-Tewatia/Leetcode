//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:

    // bool solve(vector<int> &arr,int sum,int n,vector<vector<int>> & dp){
    //     if(n==0){
    //         if(sum==0)
    //         return true;
    //         else
    //         return false;
    //     }
        
    //     if(sum==0)
    //     return true;
        
    //     if(dp[n][sum]!=-1)
    //     return dp[n][sum];
        
    //     bool left,right=false;
    //     if(arr[n-1]<=sum)
    //     left=solve(arr,sum-arr[n-1],n-1,dp) or solve(arr,sum,n-1,dp);
    //     else
    //   right= dp[n][sum]=solve(arr,sum,n-1,dp);
        
    //     return dp[n][sum]=left or right;
        
    // }
    // bool isSubsetSum(vector<int>arr, int sum){
    //     int n=arr.size();
    //     vector<vector<int>> dp(n+1,vector<int>(sum+1),-1);
    //     return solve(arr,sum,n-1,dp);
    // }
    
    bool solve(vector<int> &arr,int sum,int n,vector<vector<int>> & dp){
        if(n==0){
            if(sum==0)
            return true;
            else
            return false;
        }
        
        if(sum==0)
        return true;
        
        if(dp[n][sum]!=-1)
        return dp[n][sum];
        
        bool left,right=false;
        if(arr[n-1]<=sum)
        left=solve(arr,sum-arr[n-1],n-1,dp) or solve(arr,sum,n-1,dp);
        else
       right= dp[n][sum]=solve(arr,sum,n-1,dp);
        
        return dp[n][sum]=left or right;
        
    }
    bool isSubsetSum(vector<int>arr, int sum){
        int n=arr.size();
        vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
        return solve(arr,sum,n,dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends