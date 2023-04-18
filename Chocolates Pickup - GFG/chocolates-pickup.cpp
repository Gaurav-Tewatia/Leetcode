//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
    int solve(int n,int m, int i, int j, int k,vector<vector<int>> & grid, vector<vector<vector<int>>>& dp){
        if(j<0 or j>=m or k<0 or k>=m)
        return INT_MIN;
        
        if(i==n-1){
            if(j==k)
            return grid[i][j];
            else
            return grid[i][j]+grid[i][k];
        }
        
        if(dp[i][j][k]!=-1)
        return dp[i][j][k];
        
        int maxi=INT_MIN;
        for(int di=-1;di<=1;di++){
            for(int dj=-1;dj<=1;dj++){
                int ans;
                if(j==k)
                ans=grid[i][j]+solve(n,m,i+1,j+di,k+dj,grid,dp);
                else
                ans=grid[i][j]+grid[i][k]+solve(n,m,i+1,j+di,k+dj,grid,dp);
                
                maxi=max(ans,maxi);
            }
        }
        
        return dp[i][j][k]=maxi;
        
        
    }
    int solve(int n, int m, vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return solve(n,m,0,0,m-1,grid,dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends