class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        vector<pair<int,double>> adj[n+1];
        
       for(int i=0;i<edges.size();i++){
           adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
           adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
       }

        // //for checking purpose
        // for(int i=0;i<n;i++){
        //     for(auto it:adj[i])
        //         cout<<i<<"->"<<it.first<<"["<<it.second<<"]"<<" ";
        // }
        // cout<<endl;
        
    priority_queue<pair<double,int>> pq;
        vector<double> prob(n,0);
        prob[start]=1;
        pq.push({1,start});
        
        while(!pq.empty()){
            double probb=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            
            for(auto it:adj[node]){
                int adjnode=it.first;
                double wt=it.second;
                
                if(double(probb*wt)>prob[adjnode]){
                    prob[adjnode]=(double)(probb*wt);
                    pq.push({prob[adjnode],adjnode});
                }
            }
        }
        
        // for(auto c:prob)
        //     cout<<c<<" ";
        // cout<<endl;
        return prob[end];
    }
};