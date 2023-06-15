//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    void dfs(int i,int j,vector<pair<int,int>>&v, vector<vector<int>>&vis,vector<vector<int>>&grid,int row,int col){
        vis[i][j]=1;
        
        v.push_back({i-row,j-col});
        int n=grid.size();
        int m=grid[0].size();
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        
        for(int k=0;k<4;k++){
            int nrow=i+drow[k];
            int ncol=j+dcol[k];
            if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and grid[nrow][ncol]==1 and vis[nrow][ncol]==0)
            dfs(nrow,ncol,v,vis,grid,row,col);
        }
        
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        set<vector<pair<int,int>>>s;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 and vis[i][j]==0){
                    vector<pair<int,int>>v;
                    dfs(i,j,v,vis,grid,i,j);
                    s.insert(v);
                    
                }
            
            }
        }
        
        return s.size();
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends