//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class disjoint{
    
public:
vector<int> rank, size,parent;
    disjoint(int n){
        rank.resize(n+1,0);
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    int findparent(int node){
        if(node==parent[node])
        return node;

        return parent[node]=findparent(parent[node]);  //path compression
    }

    void unionbysize(int u ,int v){
        int ult_u=findparent(u);
        int ult_v=findparent(v);

        if(ult_u==ult_v) return ;

        if(size[ult_u]<size[ult_v]){
            parent[ult_u]=ult_v;
            size[ult_v]+=size[ult_u];
        }
        else{
            parent[ult_v]=parent[ult_u];
            size[ult_u]+=size[ult_v];
        }
    }

    void unionbyrank(int u, int v){
         int ult_u=findparent(u);
        int ult_v=findparent(v);

        if(ult_u==ult_v) return;
        if(rank[ult_u]<rank[ult_v]){
            parent[ult_u]=ult_v;
            
        }
        else if(rank[ult_v]<rank[ult_u]){
            parent[ult_v]=ult_u;

        }
        else{
            parent[ult_v]=ult_u;
            rank[ult_u]++;
        }
    }

   

};

class Solution {
    private:
        void dfs(int row,int col, vector<vector<int>> &vis,vector<vector<char>>&grid){
            vis[row][col]=1;
            int n=grid.size();
            int m=grid[0].size();
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    int nrow=row+i;
                    int ncol=col+j;
                    if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and grid[nrow][ncol]=='1'
                    and vis[nrow][ncol]==0)
                    dfs(nrow,ncol,vis,grid);
                }
            }
            
        }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // int n=grid.size();
        // int m=grid[0].size();
        // vector<vector<int>> vis(n,vector<int>(m,0));
        
        // int count=0;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if(!vis[i][j] and grid[i][j]=='1'){
        //             count++;
        //             dfs(i,j,vis,grid);
        //         }
        //     }
        // }
        // return count;
        
        
        int n=grid.size();
        int m=grid[0].size();
        
        disjoint ds(n*m);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int node=(i*m)+j;
                if(grid[i][j]=='1'){
                    for(int k=-1;k<=1;k++){
                        for(int l=-1;l<=1;l++){
                            int nrow=i+k;
                            int ncol=j+l;
                            int newnode=(nrow*m)+ncol;
                            if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and grid[nrow][ncol]=='1'
                            and ds.findparent(newnode)!=ds.findparent(node))
                            ds.unionbysize(node,newnode);
                        }
                    }
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int node=(i*m)+j;
                if(grid[i][j]=='1' and ds.parent[node]==node)
                cnt++;
            }
        }
        
        return cnt;
        
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends