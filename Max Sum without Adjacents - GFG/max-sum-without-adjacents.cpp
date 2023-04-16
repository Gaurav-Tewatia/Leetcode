//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
/*	 
recursive solution
int solve(int *height,int n){
      if(n<0)
      return 0;
      if(n==0)
      return height[n];
      
      
      int left=solve(height,n-2)+height[n];
      int right=solve(height,n-1);
      
      return max(left,right);
      
       
  }
  */
  
  int solve(int *height,int n,int *dp){
      if(n<0)
      return 0;
      if(n==0)
      return height[n];
      
      if(dp[n]!=-1)
      return dp[n];
      
      dp[n]=max(solve(height,n-2,dp)+height[n],solve(height,n-1,dp));
      return dp[n];
  }
	int findMaxSum(int *arr, int n) {
	   int dp[n];
	   memset(dp,-1,sizeof(dp));
	   return solve(arr,n-1,dp);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends