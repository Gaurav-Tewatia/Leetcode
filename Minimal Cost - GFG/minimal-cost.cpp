//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    
    int solve(vector<int> &height,int n, int m){
        int dp[n];
        memset(dp,-1,sizeof(dp));
        dp[0]=0;
        
        
        for(int k=1;k<n;k++){
            int ans=INT_MAX;
        for(int i=1;i<=m;i++){
            
            if(k>=i){
             int temp= dp[k-i]+abs(height[k]-height[k-i]);
            ans=min(ans,temp);
            }
            
        }
        dp[k]=ans;
        }
        
        return dp[n-1];
    }
    int minimizeCost(vector<int>& height, int n, int k) {

        
        
        return solve(height,n,k);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends