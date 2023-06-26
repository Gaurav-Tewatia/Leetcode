class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> vis(n,vector<int> (n,0));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({grid[0][0],{0,0}});
        vis[0][0]=1;
        vector<pair<int,int>> drc{{-1,0},{0,1},{1,0},{0,-1}};
        while(!pq.empty()){
            int time=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            
            if(row==n-1 and col==n-1)
                return time;
            for(int i=0;i<4;i++){
                int nrow=row+drc[i].first;
                int ncol=col+drc[i].second;
                
                if(nrow>=0 and nrow<n and ncol>=0 and ncol<n and vis[nrow][ncol]==0){
                    int dis=max(time,grid[nrow][ncol]);
                    vis[nrow][ncol]=1;
                    pq.push({dis,{nrow,ncol}});
                }
            }
            
            
        }
        return 0;
    }
};