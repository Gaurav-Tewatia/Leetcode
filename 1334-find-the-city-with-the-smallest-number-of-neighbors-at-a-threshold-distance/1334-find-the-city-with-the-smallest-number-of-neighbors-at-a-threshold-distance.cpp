class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
//         vector<vector<int>> matrix(n,vector<int>(n,INT_MAX));
//         for(auto c:edges){
//             matrix[c[0]][c[1]]=c[2];
//             matrix[c[1]][c[0]]=c[2];
//         }
        
//         for(int i=0;i<n;i++)matrix[i][i]=0;
//             for(int k=0;k<n;k++){
//                 for(int i=0;i<n;i++){
//                     for(int j=0;j<n;j++){
                        
//                         if(matrix[i][k]==INT_MAX or matrix[k][j]==INT_MAX) continue;
                        
//                         matrix[i][j]=min(matrix[i][j],(matrix[i][k]+matrix[k][j]));
//                     }
//                 }
//             }
        
//         int city=0;
//         int mcount=INT_MAX;
//         for(int i=0;i<n;i++){
//            int count=0;
//             for(int j=0;j<n;j++){
//                 if(matrix[i][j]<=distanceThreshold)
//                     count++;
//             }
//             if(count<=mcount){
//                 city=i;
//                 mcount=count;
//             }
//         }
//         return city;
//     }
        
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        
        vector<pair<int,int>>adj[n];
        for(auto c:edges){
            adj[c[0]].push_back({c[1],c[2]});
            adj[c[1]].push_back({c[0],c[2]});
        }
        
        int city;
        int mcount=INT_MAX;
        
        for(int i=0;i<n;i++){
            pq.push({0,i});
            vector<int> dis(n,1e9);
            int count=0;
            dis[i]=0;
            while(!pq.empty()){
                int dist=pq.top().first;
                int node=pq.top().second;
                pq.pop();
                
                for(auto c:adj[node]){
                    int adjnode=c.first;
                    int wt=c.second;
                    if(dist+wt<dis[adjnode]){
                        if(dist+wt<=distanceThreshold){
                            if(dis[adjnode]>distanceThreshold)
                                count++;
                        }
                        dis[adjnode]=dist+wt;
                        pq.push({dis[adjnode],adjnode});
                        
                    }
                }
            }
            if(count<=mcount){
                city=i;
                mcount=count;
            }
        }
        
        return city;
        
    }
};