class Solution {
public:
    
    int countPaths(int n, vector<vector<int>>& roads) {
        int modulo=(int)(1e9+7);
         vector<pair<int,int>> adj[n];
    for(auto it:roads){
        adj[it[0]].push_back({it[1],it[2]});
        adj[it[1]].push_back({it[0],it[2]});
    }

    vector<long long> ways(n,0);
   vector<long long> dis(n,1e18);

    ways[0]=1;
    dis[0]=0;

    typedef pair<long long,long long> pi;

    priority_queue<pi,vector<pi> ,greater<pi> > pq;
    pq.push({0,0});

    while(!pq.empty()){
        long long dist=pq.top().first;
        int node=pq.top().second;

        pq.pop();
        for(auto it:adj[node]){
            int v=it.first;
            long long wt=it.second;

            if(dist+wt<dis[v]){
                dis[v]=dist+wt;
                ways[v]=ways[node];
                pq.push({dis[v],v});
            }
            else if(dist+wt==dis[v]) ways[v]=(ways[v]+ways[node])%modulo;
        }
    }

    
    return ways[n-1]%modulo;
    }
};