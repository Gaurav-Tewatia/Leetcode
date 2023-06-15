class Solution {
private:
    void dfs(int i, int j, vector<vector<int>>&vis,vector<vector<char>>&board,int drow[],int *dcol){
        vis[i][j]=1;
        
        int n=board.size();
        int m=board[0].size();
        
        for(int k=0;k<4;k++){
            int nrow=i+drow[k];
            int ncol=j+dcol[k];
            if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and vis[nrow][ncol]==0 and board[nrow][ncol]=='O'){
                dfs(nrow,ncol,vis,board,drow,dcol);
            }
        }
        
    }
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size(),m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 or i==n-1 or j==0 or j==m-1){
                    if(board[i][j]=='O'){
                        
                        dfs(i,j,vis,board,drow,dcol);
                    }
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' and vis[i][j]==0)
                    board[i][j]='X';
            }
        }
        
    }
};