//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
  int solve(vector<int>&dp,vector<int> &height,int n){
      
        if(n==0)
        return 0;
        
        if(dp[n]!=-1)
        return dp[n];
        
        int left=solve(dp,height,n-1)+abs(height[n]-height[n-1]);
        int right=INT_MAX;
        if(n>1)
        right=solve(dp,height,n-2)+abs(height[n]-height[n-2]);
        
        return dp[n]=min(left,right);
        
  }
    int minimumEnergy(vector<int>& height, int n) {
        
        vector<int> dp(100000,-1);
        return solve(dp,height,n-1);
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends