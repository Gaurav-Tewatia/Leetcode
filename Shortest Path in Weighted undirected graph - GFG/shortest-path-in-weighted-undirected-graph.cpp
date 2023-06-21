//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<pair<int,int>> adj[n+1];
        for(auto c:edges){
            adj[c[0]].push_back({c[1],c[2]});
            adj[c[1]].push_back({c[0],c[2]});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,1});
        vector<int>dis(n+1,1e9);
        vector<int>parent(n+1);
        for(int i=0;i<n+1;i++){
            parent[i]=i;
        }
        
        dis[1]=0;
        
        while(!pq.empty()){
            int dist=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            
            if(node==n)
            break;
            
            for(auto c:adj[node]){
                
                int adjnode=c.first;
                int wt=c.second;
                if(dist+wt<dis[adjnode]){
                    parent[adjnode]=node;
                    dis[adjnode]=dist+wt;
                    pq.push({dis[adjnode],adjnode});
                }
            }
        }
        vector<int> ans;
        int node=n;
        if(dis[node]==1e9) return {-1};
        while(parent[node]!=node){
            ans.push_back(node);
            node=parent[node];
        }
        ans.push_back(node);
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends