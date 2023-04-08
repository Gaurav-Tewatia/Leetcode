class Solution {
public:
    bool possible(vector<vector<char>> &board,int number, int i, int j,int n){
        
        for(int k=0;k<n;k++){
            if(board[k][j]==number+'0' or board[i][k]==number+'0')
                return false;
        }
            int sq=sqrt(n);
            int sr=(i/sq)*sq;
            int sc=(j/sq)*sq;
            
            for(int x=sr;x<(sr+sq);x++){
                for(int y=sc;y<(sc+sq);y++){
                    if(board[x][y]==number+'0')
                        return false;
                }
                
            }
        
        return true;
            
        
    }
    bool solving(vector<vector<char>> &board,int i, int j,int n){
        
        if(i==n)
            return true;
        if(j==n)
            return solving(board,i+1,0,n);
        
        if(board[i][j]!='.')
            return solving(board,i,j+1,n);
    
        for(int number=1;number<=9;number++){
            
            if(possible(board,number,i,j,n)){
                board[i][j]=number+'0';
                if(solving(board,i,j+1,n))
                    return true;
            }
            board[i][j]='.';
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        
        int n=board.size();
        
        
        solving(board,0,0,n);
    }
};