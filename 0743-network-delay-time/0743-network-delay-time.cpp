class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k}); //node,time;
        
        vector<int>dis(n+1,1e9);
        dis[k]=0;
        int maxi=0;
        while(!pq.empty()){
            int time=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            
           
            for(auto c:adj[node]){
                int adjnode=c.first;
                int wt=c.second;
                
                if(time+wt<dis[adjnode]){
                    dis[adjnode]=time+wt;
                    pq.push({dis[adjnode],adjnode});
                    
                }
            }
        }
        
        for(int i=1;i<n+1;i++){
            if(dis[i]==1e9) return -1;
            maxi=max(maxi,dis[i]);
        }
        return maxi;
    }
};