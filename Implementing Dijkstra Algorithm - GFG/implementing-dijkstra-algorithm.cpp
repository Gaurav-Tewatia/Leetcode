//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    { //using priority queue
    //as using queue will unnecessariyly increase the no. of iterations
        // vector<int> dis(V,1e9);
        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        // pq.push({0,S});
        // dis[S]=0;
        // while(!pq.empty()){
        //     int dist=pq.top().first;
        //     int node=pq.top().second;
        //     pq.pop();
            
        //     for(auto c:adj[node]){
        //         int adjnode=c[0];
        //         int wt=c[1];
        //         if(dist+wt<dis[adjnode]){
        //             dis[adjnode]=dist+wt;
        //             pq.push({dis[adjnode],adjnode});
        //         }
        //     }
            
        // }
        // return dis;
        
        //
        vector<int> dist(V,1e9);
        set<pair<int,int>>s;
        s.insert({0,S});
        dist[S]=0;
        
        while(!s.empty()){
            auto it=*(s.begin());
            int dis=it.first;
            int node=it.second;
            
            s.erase(it);
            
            for(auto c:adj[node]){
                int adjnode=c[0];
                int wt=c[1];
                if(dis+wt<dist[adjnode]){
                    if(dist[adjnode]!=1e9)
                    s.erase({dist[adjnode],adjnode});
                    
                    dist[adjnode]=dis+wt;
                    s.insert({dist[adjnode],adjnode});
                }
            }
            
        }
        return dist;
        
        
        
        
        
        
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends