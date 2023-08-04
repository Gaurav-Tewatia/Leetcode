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
    int largestIsland(vector<vector<int>>& grid) {
      int n=grid.size();
	disjoint ds(n*n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(grid[i][j]==1){
				int dr[]={-1,0,1,0,-1};
				int node=i*n+j;
				for(int k=0;k<4;k++){
					int nrow=i+dr[k];
					int ncol=j+dr[k+1];

					if(nrow>=0 and nrow<n and ncol>=0 and ncol<n and grid[nrow][ncol]==1){
						int adjnode=nrow*n+ncol;
						ds.unionbysize(adjnode,node);
					}
				}
			}
		}
	}

	int mx=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(grid[i][j]==0){
				set<int>st;
				int dr[]={-1,0,1,0,-1};
				
				for(int k=0;k<4;k++){
					int nrow=i+dr[k];
					int ncol=j+dr[k+1];

					if(nrow>=0 and nrow<n and ncol>=0 and ncol<n and grid[nrow][ncol]==1){
						int adjnode=nrow*n+ncol;
						st.insert(ds.findparent(adjnode));
					}
					
				}
				int cnt=0;
				for(auto it:st){
					cnt+=ds.size[it];
				}
				mx=max(mx,cnt+1);
			}

				
		}
	}

	for(int i=0;i<n*n;i++){
		mx=max(mx,ds.size[ds.findparent(i)]);
	}
	return mx;
    }
};