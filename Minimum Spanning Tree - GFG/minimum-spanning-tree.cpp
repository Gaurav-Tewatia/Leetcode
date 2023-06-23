//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

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


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {   
        //prim's algo
        
        // vector<int> vis(V,0);
        
        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        // pq.push({0,0});
        // int sum=0;
        // while(!pq.empty()){
        //     int dis=pq.top().first;
        //     int node=pq.top().second;
        //     pq.pop();
        //     if(vis[node]) continue;
            
        //     vis[node]=1;
        //     sum+=dis;
            
        //     for(auto c:adj[node]){
        //         int adjnode=c[0];
        //         int wt=c[1];
                
        //         if(!vis[adjnode]){
        //             pq.push({wt,adjnode});
        //         }
        //     }
        // }
        // return sum;
    
        
        
    
        
        disjoint ds(V);
        vector<pair<int,pair<int,int>>> edges;
        for(int i=0;i<V;i++){
            for(auto c:adj[i]){
                int u=i;
                int v=c[0];
                int wt=c[1];
                
                edges.push_back({wt,{u,v}});
            }
        }
        
        sort(edges.begin(),edges.end());
        int mst=0;
        for(auto c:edges){
            int wt=c.first;
            int u=c.second.first;
            int v=c.second.second;
            
            if(ds.findparent(u)!=ds.findparent(v)){
                mst+=wt;
            
            }
            ds.unionbysize(u,v);
            
        }
        
        return mst;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends