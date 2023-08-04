class disjoint{
	vector<int> rank,parent,size;
	public:
	disjoint(int n){
		rank.resize(n+1,0);
		size.resize(n+1,1);
		parent.resize(n+1);
		for(int i=0;i<=n;i++) parent[i]=i;
	}

	int findparent(int node){
		if(node==parent[node]) return node;

		return parent[node]=findparent(parent[node]);
	}

	void unionbysize(int u,int v){
		int ult_u=findparent(u);
		int ult_v=findparent(v);
		if(ult_u==ult_v) return;
		if(size[ult_u]<=size[ult_v]){
			parent[ult_u]=ult_v;
			size[ult_v]+=size[ult_u];
		}
		else{
			parent[ult_v]=ult_u;
			size[ult_v]+=size[ult_u];
		}
	}

	void unionbyrank(int u,int v){
		int ult_u=findparent(u);
		int ult_v=findparent(v);
		if(ult_u==ult_v) return;

		if(rank[ult_u]<rank[ult_v]){
			parent[ult_u]=ult_v;

		}
		else if(rank[ult_v]<rank[ult_u])
		parent[ult_v]=ult_u;
		else{
			parent[ult_u]=ult_v;
			rank[ult_v]++;
		}
	}
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        
        int maxrow=0;
        int maxcol=0;
        int n=stones.size();
        for(auto it:stones){
            maxrow=max(maxrow,it[0]);
            maxcol=max(maxcol,it[1]);
        }
        disjoint ds(maxrow+maxcol+1);
        
        unordered_map<int,int> mp;
        for(auto it:stones){
            ds.unionbysize(it[0],it[1]+maxrow+1);
            mp[it[0]]=1;
            mp[it[1]+maxrow+1]=1;
        }
        int cnt=0;
        for(auto it:mp){
            if(ds.findparent(it.first)==it.first) cnt++;
                
        }
        
        return  n-cnt;
        
    
    }
};