class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        if(grid[0][0] or grid[n-1][m-1]) return -1;
        
        if(grid.size()==1 and grid[0].size()==1 and grid[0][0]==0)
            return 1;
        
        queue<pair<int,pair<int,int>>>q;
        
        q.push({1,{0,0}});
        
        vector<vector<int>>dis(n,vector<int>(m,1e9));
        dis[0][0]=1;
        
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int dist=it.first;
            int row=it.second.first;
            int col=it.second.second;
            
           for(int i=-1;i<=1;i++){
               for(int j=-1;j<=1;j++){
                int nrow=row+i;
                int ncol=col+j;
                
                    if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and grid[nrow][ncol]==0 and dist+1<dis[nrow][ncol]){
                    dis[nrow][ncol]=dist+1;
                        if(nrow==n-1 and ncol==m-1)
                            return dist+1;
                        q.push({dist+1,{nrow,ncol}});
                    }
                }
            }
        }
        return -1;
    }
};