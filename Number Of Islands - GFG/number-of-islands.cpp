//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
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
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        vector<int> ans;
    disjoint ds(n*m);
    int cnt=0;
    vector<vector<int>> vis(n,vector<int> (m,0));

    for(auto it:operators){
        int row=it[0];
        int col=it[1];
        if(vis[row][col]==1){
            ans.push_back(cnt);
            continue;
        }
        vis[row][col]=1;
         cnt++;
         int node=row*m+col;
         
         int dr[]={-1,0,1,0,-1};
         for(int i=0;i<4;i++){
             int nrow=row+dr[i];
             int ncol=col+dr[i+1];

             if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and vis[nrow][ncol]==1){
                 int adjnode=nrow*m+ncol;
                 if(ds.findparent(node)!=ds.findparent(adjnode)){
                     cnt--;
                     ds.unionbysize(adjnode,node);
                 }
                 
             }
         }
         ans.push_back(cnt);
    }

    return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends