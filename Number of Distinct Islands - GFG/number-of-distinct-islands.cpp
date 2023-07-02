//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
    void dfs(int r,int c,int sr,int sc,vector<vector<int>>&grid
    ,vector<pair<int,int>>&a,vector<vector<int>>&vis){
        vis[r][c]=1;
        a.push_back({r-sr,c-sc});
        int n=grid.size();
        int m=grid[0].size();
        int delr[]={1,0,-1,0};
        int delc[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int row=r+delr[i];
            int col=c+delc[i];
            if(row>=0 and row<n and col>=0 and col<m and 
            !vis[row][col] and grid[row][col]==1){
                dfs(row,col,sr,sc,grid,a,vis);
            }
        }
        return ;
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        set<vector<pair<int,int>>>st;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vector<pair<int,int>>a;
                if(vis[i][j]==0 and grid[i][j]==1){
                    dfs(i,j,i,j,grid,a,vis);
                    st.insert(a);
                }
            }
        }
        return st.size();
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