class Solution {
    private:
    bool check(int row,int col,int n, int m){
    return row>=0 and row<n and col>=0 and col<m;
}
bool helper(int row,int col,int n, int m,vector<vector<char>> &board,string &word,vector<vector<int>> &vis,int index){
    if(index==word.size()) return true;
    
   

    int dr[]={-1,0,1,0,-1};
    

    for(int i=0;i<4;i++){
        int nrow=row+dr[i];
        int ncol=col+dr[i+1];

        if(check(nrow,ncol,n,m) and board[nrow][ncol]==word[index] and vis[nrow][ncol]==0){
            vis[nrow][ncol]=1;
            
            if(helper(nrow,ncol,n,m,board,word,vis,index+1))
            return true;
            vis[nrow][ncol]=0;
        }
    }
    
    return false;
}
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
    
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    vis[i][j]=1;
                    
                    if(helper(i,j,n,m,board,word,vis,1))
                        return true;
                        
                    vis[i][j]=0;
                }
                
            }
        }
        return false;
    }
    
    
};