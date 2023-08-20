//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // vector<int> adj[n+1];
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         if(i==j) continue;
        //         if(M[i][j]==1) adj[i].push_back(j);
        //     }
        // }
        // vector<int> ::iterator it;
        // for(int i=0;i<n;i++){
        //     if(adj[i].empty()){
        //         bool flag=1;
        //         for(int j=0;j<n;j++){
        //             if(j!=i){
        //                 it=find(adj[j].begin(),adj[j].end(),i);
        //                 if(it==adj[j].end()){
        //                      flag=0;
        //                      break;
        //                 }
                       
        //             }
        //         }
        //         if(flag) return i;
        //     }
        // }
        // return -1;
    
        
        vector<int> indegree(n,0),outdegree(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(M[i][j]){
                    indegree[j]++;
                    outdegree[i]++;
                }
            }
        }
        
        for(int i=0;i<n;i++){
            if(indegree[i]==n-1 and outdegree[i]==0) return i;
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends