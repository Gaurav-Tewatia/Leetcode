//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
    private:
     bool dfs(int node, int *vis, int *path,vector<int> adj[]){
         vis[node]=1;
         path[node]=1;
         
         for(auto c:adj[node]){
             if(vis[c]==0)
             {
                 if(dfs(c,vis,path,adj)==true) return true;
             }
             else if(path[c]==1)
             return true;
         }
         path[node]=0;
         return false;
     }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
       
    //   int vis[V]={0};
    //   int path[V]={0};
       
    //   for(int i=0;i<V;i++){
    //       if(vis[i]==0)
    //       {
    //           if(dfs(i,vis,path,adj)==true) return true;
    //       }
    //   }
    //   return false;
    
    //using topological sort
    
    int indegree[V]={0};
    for(int i=0;i<V;i++){
        for(auto c:adj[i])
        indegree[c]++;
    }
    
    queue<int> q;  //store the order
    for(int i=0;i<V;i++){
        if(indegree[i]==0)
        q.push(i);  //pushed all the nodes which have no parent node
    }
    vector<int> topo;
        while(!q.empty()){
            int a=q.front();
            topo.push_back(a);
            q.pop();
            
            for(auto it:adj[a]){
                indegree[it]--;
                if(indegree[it]==0)
                q.push(it);
            }
        }
        
        if(topo.size()<V){
            return true;
        }
        else
        return false;
    }
};







//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends