//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends



class Solution {
  public:
  vector<vector<int>> dp;
  int solve(int i,int n,vector<vector<int>> &points,int prev)
  {
      if(i==n)
      {
          return 0;
      }
      if(dp[i][prev+1]!=-1)
      {
          return dp[i][prev+1];
      }
      int mx=0;
      for(int j=0;j<3;j++)
      {
          if(j!=prev)
          {
              mx=max(mx,points[i][j]+solve(i+1,n,points,j));
          }
      }
      return dp[i][prev+1]=mx;
  }
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        dp.resize(n,vector<int>(4,-1));
        return solve(0,n,points,-1);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends