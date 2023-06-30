//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
    typedef pair<int,pair<int,int>> piii;
class Solution
{
    public:
        int minimumCost(int n,vector<vector<int>> &cars,int src,int dst,int k)
        {   
            vector<pair<int,int>> adj[n];
            
            for(auto it:cars){
                adj[it[0]].push_back({it[1],it[2]});
            }
            
            vector<int> dis(n,1e9);
            priority_queue<piii,vector<piii>,greater<piii>> pq;
            pq.push({0,{0,src}});
            dis[src]=0;
            
            while(!pq.empty()){
                int steps=pq.top().first;
                int dist=pq.top().second.first;
                int node=pq.top().second.second;
                
                pq.pop();
                if(steps>k) continue;
                
                for(auto it:adj[node]){
                    int adjnode=it.first;
                    int wt=it.second;
                    
                    if(dist+wt<dis[adjnode]){
                        dis[adjnode]=dist+wt;
                        
                        pq.push({steps+1,{dis[adjnode],adjnode}});
                    }
                }
            }
            if(dis[dst]==1e9) return -1;
            return dis[dst];
            
            
        }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,src,dst,k;
        cin>>n>>src>>dst>>k>>m;
        vector<vector<int>> cars(m,vector<int> (3));
        for(auto &j:cars)
            cin>>j[0]>>j[1]>>j[2];
        Solution s;
        cout<<s.minimumCost(n,cars,src,dst,k)<<endl;
    }
    return 0;
}
// } Driver Code Ends