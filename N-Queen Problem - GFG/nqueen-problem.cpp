//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    bool check(int row,int col,int n ,vector<int> &upperd,vector<int> &lowerd,vector<int>& horirow){
        return horirow[row]==0 and upperd[row+col]==0 and lowerd[n-1+col-row]==0;
    }
    void mark(int row,int col,int n,vector<int> &upperd,vector<int> &lowerd,vector<int> &horirow){
        if(horirow[row]==0){
            horirow[row]=1;
            upperd[row+col]=1;
            lowerd[n-1+col-row]=1;
        }
        else{
            horirow[row]=0;
            upperd[row+col]=0;
            lowerd[n-1+col-row]=0;
        }
    }
    void helper(int col,int n,vector<int> &v,vector<vector<int>>&ans,vector<int>&upperd,vector<int>&lowerd,vector<int>&horirow){
        if(col==n){
            ans.push_back(v);
            return;
        }
        
        for(int row=0;row<n;row++){
            if(check(row,col,n,upperd,lowerd,horirow)){
                v.push_back(row+1);
                mark(row,col,n,upperd,lowerd,horirow);
                helper(col+1,n,v,ans,upperd,lowerd,horirow);
                mark(row,col,n,upperd,lowerd,horirow);
                v.pop_back();
            }
        }
    }
public:
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> ans;
        vector<int> v;
        vector<int> upperd(2*n-1,0),lowerd(2*n-1,0),horirow(n,0);
        helper(0,n,v,ans,upperd,lowerd,horirow);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends