class Solution {
private:
    bool dfs(int start,int col,int *color,vector<int> adj[]){
        color[start]=col;
        
        for(auto c:adj[start]){
            if(color[c]==-1){
                if(dfs(c,!col,color,adj)==false)
                    return false;
            }
            else if(color[c]==col)
                return false;     
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                adj[i].push_back(graph[i][j]);
                
            }
        }
        
        int color[n];
        for(int i=0;i<n;i++){
            color[i]=-1;
        }
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(dfs(i,0,color,adj)==false)
                     return false;   
            }
        }
        return true;
        

    }
};