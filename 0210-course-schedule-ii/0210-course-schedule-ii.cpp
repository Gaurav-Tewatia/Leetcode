class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        int indegree[numCourses];
        for(int i=0;i<numCourses;i++){
            indegree[i]=0;
        }
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) q.push(i);
        }
        
        vector<int> topo;
        while(!q.empty()){
            int node=q.front();
            
            topo.push_back(node);
                q.pop();
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0)q.push(it);
            }
        }
        if(topo.size()!=numCourses) return {};
            return topo;
    }
};