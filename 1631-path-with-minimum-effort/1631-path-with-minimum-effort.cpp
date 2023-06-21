class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        int n=heights.size();
        int m=heights[0].size();
        
        int dis[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dis[i][j]=1e9;
            }
        }
        dis[0][0]=0;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        
        pq.push({0,{0,0}});
        
        while(!pq.empty()){
            int dist=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            
            pq.pop();
            
            for(int i=0;i<4;i++){
                int nrow=row+dr[i];
                int ncol=col+dc[i];
                
                if(nrow>=0 and nrow<n and ncol>=0 and ncol<m){
                    int neweffort=max(abs(heights[nrow][ncol]-heights[row][col]),dist);
                    if(neweffort<dis[nrow][ncol]){
                        dis[nrow][ncol]=neweffort;
                        pq.push({neweffort,{nrow,ncol}});
                    }
                        
                }
            }
        }
        return dis[n-1][m-1];
    }
};