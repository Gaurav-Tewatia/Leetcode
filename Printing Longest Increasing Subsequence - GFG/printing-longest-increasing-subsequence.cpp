//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
            vector<int> dp(n,1),hash(n,0);
            int lastindex=0;
            int maxi=0;
            for(int i=0;i<n;i++){
                hash[i]=i;
                for(int prev=0;prev<i;prev++){
                    if(arr[prev]<arr[i] and 1+dp[prev]>dp[i]){
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
            ans.push_back(arr[lastindex]);
            while(hash[lastindex]!=lastindex){
                
                lastindex=hash[lastindex];
                
                ans.push_back(arr[lastindex]);
            }
            
            reverse(begin(ans),end(ans));
            
            return ans;
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
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends