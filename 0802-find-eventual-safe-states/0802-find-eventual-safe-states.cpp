class Solution {
private:
    bool dfs(int node, int *vis,int *path,vector<int>adj[],vector<int> &ans){
        vis[node]=1;
        path[node]=1;
        // check[node]=0;
        
        for(auto c:adj[node]){
            if(!vis[c]){
                if(dfs(c,vis,path,adj,ans)==true)
                {
                    // check[node]=0;
                    return true;
                }
            }
            else if(path[c])
                return true;
        }
        ans.push_back(node);
        path[node]=0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                adj[i].push_back(graph[i][j]);
            }
        }
        
        int vis[n];
        int path[n];
        int check[n];
        for(int i=0;i<n;i++){
            vis[i]=0;
            path[i]=0;
            check[i]=0;
        }
         vector<int> ans;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,path,adj,ans);
            }
        }
        
       
        // for(int i=0;i<n;i++){
        // if(check[i]==1)
        //     ans.push_back(i);
        // }
        
        sort(ans.begin(),ans.end());
            return ans;
    }
};