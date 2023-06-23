class disjoint{
    
public:
vector<int> rank, size,parent;
    disjoint(int n){
        rank.resize(n+1,0);
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    int findparent(int node){
        if(node==parent[node])
        return node;

        return parent[node]=findparent(parent[node]);  //path compression
    }

    void unionbysize(int u ,int v){
        int ult_u=findparent(u);
        int ult_v=findparent(v);

        if(ult_u==ult_v) return ;

        if(size[ult_u]<size[ult_v]){
            parent[ult_u]=ult_v;
            size[ult_v]+=size[ult_u];
        }
        else{
            parent[ult_v]=parent[ult_u];
            size[ult_u]+=size[ult_v];
        }
    }

    void unionbyrank(int u, int v){
         int ult_u=findparent(u);
        int ult_v=findparent(v);

        if(ult_u==ult_v) return;
        if(rank[ult_u]<rank[ult_v]){
            parent[ult_u]=ult_v;
            
        }
        else if(rank[ult_v]<rank[ult_u]){
            parent[ult_v]=ult_u;

        }
        else{
            parent[ult_v]=ult_u;
            rank[ult_u]++;
        }
    }

   

};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,int> mp;
        int n=accounts.size();
        disjoint ds(n);
        
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string str=accounts[i][j];
                if(mp.find(str)==mp.end())
                    mp[str]=i;
                else{
                    ds.unionbysize(i,mp[str]);
                }
            }
        }
        
        vector<string> temp[n];
        
       for(auto c:mp){
           string st=c.first;
           int node=ds.findparent(c.second);
           
           temp[node].push_back(st);     
       }
        
        vector<vector<string>> ans;
            for(int i=0;i<n;i++){
                if(temp[i].size()==0) continue;
                sort(temp[i].begin(),temp[i].end());
                vector<string> p;
                p.push_back(accounts[i][0]);
                for(auto c:temp[i]){
                    p.push_back(c);
                }
                
                ans.push_back(p);
            }
        
        
        return ans;
    }
};