class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
       vector<pair<int,int>> adj[n];
 
        for(auto c:flights){
            adj[c[0]].push_back({c[1],c[2]});
        }
               priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vector<int> dis(n,1e9);
        dis[src]=0;
        
        pq.push({0,{src,0}}); //dis,node,kvalue
        while(!pq.empty()){
            int kvalue=pq.top().first;
            int node=pq.top().second.first;
            int dist=pq.top().second.second;
            
            pq.pop();
            
            if(kvalue>k)
                continue;
            
            for(auto c:adj[node]){
                int adjnode=c.first;
                int wt=c.second;
                if(dist+wt<dis[adjnode] and kvalue<=k){
                    dis[adjnode]=dist+wt;
                    pq.push({kvalue+1,{adjnode,dis[adjnode]}});
                    
                }
            }
        }
         if (dis[dst] == 1e9)
            return -1;
        return dis[dst];
    }
};