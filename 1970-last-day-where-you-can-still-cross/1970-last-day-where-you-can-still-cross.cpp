class Solution {
    private:
    bool check(int mid, vector<vector<int> > &cells,int row,int col){
        vector<vector<int>> vis(row,vector<int>(col,0));
        
        for(int i=0;i<mid;i++){
            vis[cells[i][0]-1][cells[i][1]-1]=1;
        }
        queue<pair<int,int>> q;
        for(int i=0;i<col;i++){
            if(vis[0][i]==0){
                q.push({0,i});
                    vis[0][i]=1;
            }
                
        }
        
        int dc[]={0,1,0,-1,0};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            
            if(r==row-1) return true;
            
            for(int i=0;i<4;i++){
                int nrow=r+dc[i];
                int ncol=c+dc[i+1];
                if(nrow==row or nrow<0 or ncol==col or ncol<0 or vis[nrow][ncol]==1) continue;
                
                vis[nrow][ncol]=1;
                q.push({nrow,ncol});
            }
            
        }
        return false;
    }
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int low=1,high=cells.size();
        int ans;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(mid,cells,row,col)){
                ans=mid;
                low=mid+1;
            }
            else
                high=mid-1;
        }
        
        return high;
        
    }
};