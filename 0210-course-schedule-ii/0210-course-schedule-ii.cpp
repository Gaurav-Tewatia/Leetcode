class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
         vector<int> adj[numCourses];
        for(auto it:prerequisites)
            adj[it[1]].push_back(it[0]);
        
        int indegree[numCourses];
        for(int i=0;i<numCourses;i++){
            indegree[i]=0;
        }
        
        for(int i=0;i<numCourses;i++){
            for(auto c:adj[i])
                indegree[c]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)
                q.push(i);
        }
        
        vector<int> topo;
        
        while(!q.empty()){
            int a=q.front();
            topo.push_back(a);
            q.pop();
            
            for(auto c:adj[a]){
                indegree[c]--;
                if(indegree[c]==0)
                    q.push(c);
            }
        }
        if(topo.size()==numCourses)
            return topo;
        else
            return {};
    }
};