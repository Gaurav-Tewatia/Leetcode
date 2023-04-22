//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    int countPartitions(int n, int d, vector<int>& arr) {
        int modulo=1000000007;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        if((sum+d)%2)
        return 0;
        
        int find=(sum+d)/2;
        
        
        
        vector<vector<int>> dp(n+1, vector<int>(find+1, 0));
        for(int i=0;i<=n;i++){
            for(int j=0;j<=find;j++){
                if(i==0)
                dp[i][j]=0;
                
            }
        }
        dp[0][0]=1;
        
        for(int i=1;i<=n;i++){
            for(int j=0;j<=find;j++){
                if(arr[i-1]<=j)
                dp[i][j]=(dp[i-1][j-arr[i-1]] + dp[i-1][j])%modulo;
                else
                dp[i][j]=dp[i-1][j];
            }
        }
        
        return dp[n][find]%modulo;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends