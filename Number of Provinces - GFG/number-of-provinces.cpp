//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

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
        
        vector<int> adjls[V];
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(adj[i][j]==1 and i!=j){
                    adjls[i].push_back(j);
                    
                }
            }
        }
        int vis[V]={0};
        int count=0;
        // for(int i=0;i<V;i++){
        //     if(!vis[i]){
        //         dfs(i,adjls,vis);
        //         count++;
        //     }
        // }
        
        queue<int>q;
        
        for(int i=0;i<V;i++){
            if(vis[i]==0)
            {
                vis[i]=1;
                q.push(i);
                
                while(!q.empty()){
                int a=q.front();
                q.pop();
                for(auto c:adjls[a])
                {
                    if(!vis[c]){
                        vis[c]=1;
                        q.push(c);
                    }
                }
            }
            count++;
            }
            
            
        }
        
        return count;
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