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
        vector<vector<int>> arr(n,vector<int>(m,0));
        
        disjoint ds(n*m);
        
        vector<int> ans;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        int cnt=0;
        for(auto c:operators){
            int row=c[0];
            int col=c[1];
            if(arr[row][col]==1)
            {
                ans.push_back(cnt);
                continue;
            }
            arr[row][col]=1;
            int node=row*m+col;
            cnt++;
            for(int i=0;i<4;i++){
                int nrow=row+dr[i];
                int ncol=col+dc[i];
                int newnode=nrow*m+ncol;
                if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and arr[nrow][ncol]==1
                and ds.findparent(newnode)!=ds.findparent(node)){
                    cnt--;
                    ds.unionbysize(node,newnode);
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