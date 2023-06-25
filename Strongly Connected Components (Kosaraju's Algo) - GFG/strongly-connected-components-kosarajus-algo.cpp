//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    private:
        void dfs(int node,stack<int> &st, vector<int> &vis,vector<vector<int>>& adj){
            vis[node]=1;
            
            for(auto c:adj[node]){
                if(!vis[c])
                dfs(c,st,vis,adj);
            }
            
            st.push(node);
        }
        
        void dfs2(int node, vector<int> &vis,vector<int> revadj[]){
            vis[node]=1;
            
            for(auto c:revadj[node]){
                if(!vis[c])
                dfs2(c,vis,revadj);
            }
        }
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        
        stack<int> st;
        vector<int> vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i])
            dfs(i,st,vis,adj);
        }
        
        vector<int>revadj[V];
        
        for(int i=0;i<V;i++){
            vis[i]=0;
            for(auto c:adj[i]){
                //i-->c
                revadj[c].push_back(i);
                
            }
        }
        int cnt=0;
        while(!st.empty()){
            int node=st.top();
            st.pop();
            if(!vis[node]){
                dfs2(node,vis,revadj);
                cnt++;
            }
            
        }
        
        return cnt;
    }
    
    
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends