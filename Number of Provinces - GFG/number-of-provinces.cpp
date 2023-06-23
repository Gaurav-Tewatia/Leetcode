//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class disjoint{
    
public:
vector<int> rank, size,parent;
    disjoint(int n){
        rank.resize(n+1,0);
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    int findparent(int node){
        if(node==parent[node])
        return node;

        return parent[node]=findparent(parent[node]);  //path compression
    }

    void unionbysize(int u ,int v){
        int ult_u=findparent(u);
        int ult_v=findparent(v);

        if(ult_u==ult_v) return ;

        if(size[ult_u]<size[ult_v]){
            parent[ult_u]=ult_v;
            size[ult_v]+=size[ult_u];
        }
        else{
            parent[ult_v]=parent[ult_u];
            size[ult_u]+=size[ult_v];
        }
    }

    void unionbyrank(int u, int v){
         int ult_u=findparent(u);
        int ult_v=findparent(v);

        if(ult_u==ult_v) return;
        if(rank[ult_u]<rank[ult_v]){
            parent[ult_u]=ult_v;
            
        }
        else if(rank[ult_v]<rank[ult_u]){
            parent[ult_v]=ult_u;

        }
        else{
            parent[ult_v]=ult_u;
            rank[ult_u]++;
        }
    }

   

};

class Solution {
  public:
  
  void dfs(int start, vector<int> adj[], int vis[]){
      vis[start]=1;
      for(auto c:adj[start]){
          if(!vis[c])
          dfs(c,adj,vis);
      }
  }
    int numProvinces(vector<vector<int>> adj, int V) {
        
        // vector<int> adjls[V];
        // for(int i=0;i<V;i++){
        //     for(int j=0;j<V;j++){
        //         if(adj[i][j]==1 and i!=j){
        //             adjls[i].push_back(j);
                    
        //         }
        //     }
        // }
        // int vis[V]={0};
        // int count=0;
        //this is using dfs traversal
        
        // for(int i=0;i<V;i++){
        //     if(!vis[i]){
        //         dfs(i,adjls,vis);
        //         count++;
        //     }
        // }
        
        
        
        //this is using bfs traversal
        // queue<int>q;
        
        // for(int i=0;i<V;i++){
        //     if(vis[i]==0)
        //     {
        //         vis[i]=1;
        //         q.push(i);
                
        //         while(!q.empty()){
        //         int a=q.front();
        //         q.pop();
        //         for(auto c:adjls[a])
        //         {
        //             if(!vis[c]){
        //                 vis[c]=1;
        //                 q.push(c);
        //             }
        //         }
        //     }
        //     count++;
        //     }
            
            
        // }
        
        // return count;
    
        
        
    
        //using disjoint data structure
        
    
        disjoint ds(V);
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(i!=j and adj[i][j]==1){
                    ds.unionbysize(i,j);
                }
            }
        }
        
        int cnt=0;
        for(int i=0;i<V;i++){
            if(ds.parent[i]==i) cnt++;
        }
        
        return cnt;
    }
    
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends