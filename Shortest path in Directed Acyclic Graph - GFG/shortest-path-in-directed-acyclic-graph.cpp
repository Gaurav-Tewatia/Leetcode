//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    
    private:
        void dfs(int node,int *vis, vector<pair<int,int>> adj[],stack<int> &s){
            vis[node]=1;
            
            for(auto c:adj[node]){
                int v=c.first;
                if(!vis[v])
                dfs(v,vis,adj,s);
            }
            s.push(node);
        }
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<pair<int,int>> adj[N];
        for(int i=0;i<M;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            adj[u].push_back({v,wt});
        }
        int vis[N]={0};
        stack<int> s;
        
        for(int i=0;i<N;i++){
            if(!vis[i])
            dfs(i,vis,adj,s);
        }
        
        vector<int> dis(N,1e9);
        dis[0]=0;
        
        while(!s.empty()){
            int a=s.top();
            s.pop();
            
            for(auto c:adj[a]){
                int v=c.first;
                int wt=c.second;
                if(dis[a]+wt<dis[v]){
                   dis[v]=dis[a]+wt;
                }
            }
        }
        
        for(int i=0;i<N;i++){
            if(dis[i]==1e9) dis[i]=-1;
        }
        
        return dis;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
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