class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
         typedef pair<int,pair<int,int>> pi;
    vector<pair<int,int>> adj[n];
    for(auto it:flights){
        int u=it[0];
        int v=it[1];
        int wt=it[2];
        adj[u].push_back({v,wt});
    }

    priority_queue<pi,vector<pi>, greater<pi>> pq;
    pq.push({0,{0,src}});
    vector<int> dis(n,1e9);
        dis[src]=0;
    while(!pq.empty()){
        int steps=pq.top().first;
        int dist=pq.top().second.first;
        int node=pq.top().second.second;

        pq.pop();
        if(steps>k) continue;

        for(auto it:adj[node]){
            int adjnode=it.first;
            int wt=it.second;
            if(steps<=k and dist+wt<dis[adjnode]){
                dis[adjnode]=dist+wt;
                pq.push({steps+1,{dis[adjnode],adjnode}});
            }
        }
    }
    if(dis[dst]==1e9) return -1;
    return dis[dst];
    }
};