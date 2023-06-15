class Solution {
private:
    void bfs(int i, int j, vector<vector<int>>&vis,vector<vector<int>>&grid,int *drow,int *dcol){
        vis[i][j]=1;
        queue<pair<int,int>>q;
        q.push({i,j});
        
        int n=grid.size();
        int m=grid[0].size();
        while(!q.empty()){
            int a=q.front().first;
            int b=q.front().second;
            q.pop();
            
            for(int k=0;k<4;k++){
                int nrow=a+drow[k];
                int ncol=b+dcol[k];
                if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and grid[nrow][ncol]==1 and vis[nrow][ncol]==0){
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 or i==n-1 or j==0 or j==m-1){
                    if(grid[i][j]==1 and vis[i][j]==0)
                     bfs(i,j,vis,grid,drow,dcol);
                }
            }
        }
        
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                   if(grid[i][j]==1 and vis[i][j]==0)
                       count++;
            }
        }
        return count;
    }
};