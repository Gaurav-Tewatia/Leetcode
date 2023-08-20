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
    
        //INDEGREE OUTDEGREE METHOD
        // vector<int> indegree(n,0),outdegree(n,0);
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         if(M[i][j]){
        //             indegree[j]++;
        //             outdegree[i]++;
        //         }
        //     }
        // }
        
        // for(int i=0;i<n;i++){
        //     if(indegree[i]==n-1 and outdegree[i]==0) return i;
        // }
        // return -1;
    
        
        //ELIMINATION METHOD
        // stack<int> st;
        // for(int i=0;i<n;i++) st.push(i);
        
        // while(st.size()>1){
        //     int A=st.top();
        //     st.pop();
        //     int B=st.top();
        //     st.pop();
        //     if(M[A][B]) st.push(B);
        //     else st.push(A);
        // }
        
        // int c=st.top();
        // st.pop();
        
        // for(int i=0;i<n;i++){
        //     if(i!=c and ( M[c][i] or !M[i][c])) return -1;
        // }
        // return c;
    
        
        int r=0;
        for(int i=1;i<n;i++){
            if(M[r][i]){
                M[r][r]=1;
                r=i;
            } 
            else{
                M[i][i]=1;
            }
        }
        
        int candidate;
        for(int i=0;i<n;i++){
            if(M[i][i]==0){
                bool flag=1;
                for(int j=0;j<n;j++){
                    if(i!=j and (!M[j][i] or M[i][j])){
                        flag=0;
                        break;
                    }
                }
                if(flag) return i;
            }
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