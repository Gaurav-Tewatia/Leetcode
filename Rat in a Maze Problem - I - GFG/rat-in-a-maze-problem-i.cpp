//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    bool check(int row,int col,int n,vector<vector<int>> &m,vector<vector<int>> &vis){
        return row>=0 and row<n and col>=0 and col<n and m[row][col]==1 and vis[row][col]==0;
    }
    void helper(int row,int col,int n,vector<vector<int>> &m,vector<vector<int>> &vis,string &s ,vector<string> &ans){
        if(row==n-1 and col==n-1){
            ans.push_back(s);
            return;
        }
        
        int dr[]={1,0,0,-1};
        int dc[]={0,-1,1,0};
        char dir[]={'D','L','R','U'};
        for(int i=0;i<4;i++){
            int nrow=row+dr[i];
            int ncol=col+dc[i];
            
            if(check(nrow,ncol,n,m,vis)){
                vis[nrow][ncol]=1;
                s.push_back(dir[i]);
                helper(nrow,ncol,n,m,vis,s,ans);
                s.pop_back();
                vis[nrow][ncol]=0;
            }
        }
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        if(m[0][0]==0) return {};
        
        
        
        vector<vector<int>> vis(n,vector<int> (n,0));
        
        vector<string> ans;
        string s;
        vis[0][0]=1;
        helper(0,0,n,m,vis,s,ans);
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends