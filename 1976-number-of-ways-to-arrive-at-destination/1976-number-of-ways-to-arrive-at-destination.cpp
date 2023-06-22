class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int modulo=(int)(1e9+7);
        
        vector<pair<int,int>> adj[n];
        
        for(auto c:roads){
            adj[c[0]].push_back({c[1],c[2]});
            adj[c[1]].push_back({c[0],c[2]});
        }
        
        priority_queue<pair<long long,long long>,vector<pair<long long, long long>>,greater<pair<long long, long long>>>pq;
        pq.push({0,0}); //dis,node
        vector<long long>dis(n,1e18),ways(n,0);
        int count=0;
        
        dis[0]=0;
        ways[0]=1;
        while(!pq.empty()){
            long long dist=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            
            for(auto c:adj[node]){
                int adjnode=c.first;
                int wt=c.second;
                if(dist+wt<dis[adjnode]){
                    dis[adjnode]=dist+wt;
                    pq.push({dis[adjnode],adjnode});
                    ways[adjnode]=ways[node];
                }
                else if(dist+wt==dis[adjnode]){
                    ways[adjnode]=(ways[adjnode]+ways[node])%modulo;
                }
            }
        }
        
        return ways[n-1]%modulo;
    }
};