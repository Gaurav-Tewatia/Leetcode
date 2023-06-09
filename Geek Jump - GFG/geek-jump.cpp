//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
  
  /*
  
  //top down approach
  
class Solution {
  public:
  
  int solve(vector<int> &dp, vector<int> &height,int n){
      if(n==0)
      return 0;
      
      if(dp[n]!=-1)
      return dp[n];
      
      int left=solve(dp,height,n-1)+abs(height[n]-height[n-1]);
      int right=INT_MAX;
      if(n-2>=0)
      right=solve(dp,height,n-2)+abs(height[n]-height[n-2]);
      
      return dp[n]=min(left,right);
  }
    int minimumEnergy(vector<int>& height, int n) {
        vector<int> dp(n,-1);
        return solve(dp,height,n-1);
    }
};


  */
  int solve(vector<int> &height,int n){
      int dp[n];
      dp[0]=0;
      
      for(int i=1;i<n;i++){
        int left=dp[i-1]+abs(height[i]-height[i-1]);
        int right=INT_MAX;
        if(i>1)
        right=dp[i-2]+abs(height[i]-height[i-2]);
        
        dp[i]=min(left,right);
      }
      
       
       return dp[n-1];
       
  }
    int minimumEnergy(vector<int>& height, int n) {
        
        return solve(height,n);
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