class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        int vis[n][m];
        
        queue<pair<pair<int,int>,int> >q;
        int countfresh=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    vis[i][j]=2;
                    q.push({{i,j},0});
                }
                else{
                    vis[i][j]=0;
                }
                
                if(grid[i][j]==1)
                    countfresh++;
            }
        }
        
        int tm=0;
        int count=0;
        while(!q.empty()){
            int a=q.front().first.first;
            int b=q.front().first.second;
            int time=q.front().second;
            q.pop();
            tm=max(tm,time);
            
            int drow[]={-1,0,1,0};
            int dcol[]={0,1,0,-1};
            
            for(int i=0;i<4;i++){
                int nrow=a+drow[i];
                int ncol=b+dcol[i];
                
                if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and grid[nrow][ncol]==1 and vis[nrow][ncol]==0){
                    vis[nrow][ncol]=2;
                    count++;
                    q.push({{nrow,ncol},time+1});
                }
            }
        }
        
        if(count!=countfresh)
            return -1;
        
        return tm;
    }
};