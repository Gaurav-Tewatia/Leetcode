//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
vector<long long int> dp(100001);
class Solution {
  public:
  int mod=1e9+7;
  
  
  long long int topdown(int n, vector<long long int> &dp){
         if(n==0)
     return dp[0]=0;
     if(n==1)
     return dp[1]=1;
     
     if(dp[n]!=-1)
     return dp[n];
     
      
      return dp[n]=(topdown(n-1,dp)+topdown(n-2,dp))%mod;
  }
    long long int topDown(int n) {
        
     
     return topdown(n,dp);
    }
    long long int bottomUp(int n) {
        
        vector<long long int> dp1(n+1,0);
        dp1[0]=0;
        dp1[1]=1;
        
        for(int i=2;i<=n;i++){
            dp1[i]=(dp1[i-1]+dp1[i-2])%mod;
        }
        return dp1[n]%mod;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        for (int i = 0; i < 100001; i++) dp[i] = -1;
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    }
}
// } Driver Code Ends