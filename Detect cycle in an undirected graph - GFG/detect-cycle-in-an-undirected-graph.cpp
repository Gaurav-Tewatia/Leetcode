//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
    private:
        bool checkbfs(int start,int vis[], vector<int> adj[]){
            vis[start]=1;
            queue<pair<int,int>> q;
            q.push({start,-1});
            
            while(!q.empty()){
                int a=q.front().first;
                int parent=q.front().second;
                
                q.pop();
                for(auto c:adj[a]){
                    if(!vis[c]){
                        vis[c]=1;
                        q.push({c,a});
                    }
                    else{
                        if(parent!=c)
                        return true;
                    }
                }
            }
            return false;
        }
        
        bool checkdfs(int start,int parent,int vis[], vector<int> adj[]){
            vis[start]=1;
            
            
            for(auto c:adj[start]){
                if(!vis[c]){
                    if(checkdfs(c,start,vis,adj))
                    return true;
                }
                else if(parent!=c)
                return true;
            }
            return false;
        }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V]={0};
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(/*checkbfs(i,vis,adj)*/ checkdfs(i,-1,vis,adj))
                return true;
            }
        }
        return false;
        
        
        
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends