class Solution {
public:
    typedef double var;
    int n;
    var solve(int start,int end,vector<pair<int,var>> adj[])
    {
        // modified dijkstra
        vector<var> ans(n,0);
        priority_queue<pair<var,int>> pq;
        pq.push({1,start});
        ans[start]=0;
        while(!pq.empty())
        {
            auto p=pq.top();
            pq.pop();
            auto node=p.second;
            auto cost=p.first;
            for(auto it:adj[node])
            {
                if((cost*it.second)>ans[it.first])
                {
                    ans[it.first]=cost*it.second;
                    pq.push({ans[it.first],it.first});
                }
            }
        }
        return ans[end];
    }
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int,var>> adj[n+1];
        this->n=n;
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        return solve(start,end,adj);
    }
};