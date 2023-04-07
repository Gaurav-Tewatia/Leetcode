class Solution {
public:

    bool possible(vector<vector<char>>&board,string word,int i, int j, int index){
        if (index == word.length())
            return true;

        if(i<0 or j<0 or i>=board.size() or j>=board[0].size() or board[i][j]!=word[index] or board[i][j]=='!')
        return false;

        char c=board[i][j];
        board[i][j]='!';

        bool up=possible(board,word,i-1,j,index+1);
        bool down=possible(board,word,i+1,j,index+1);
        bool left=possible(board,word,i,j-1,index+1);
        bool right=possible(board,word,i,j+1,index+1);

        board[i][j]=c;
        
        return up or down or left or right;
    }

    bool solve(vector<vector<char>>&board,string word,int index){
        int m=board.size();
        int n=board[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[index]){
                    if(possible(board,word,i,j,index))
                    return true;
                }
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int index=0;
        int flag=solve(board,word,index);
        if(flag)
        return true;
        else
        return false;
    }
};