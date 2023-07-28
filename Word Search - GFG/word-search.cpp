//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    bool check(int index,int row,int col,int n,int m , vector<vector<char>> &board,string &word){
        if(row>=0 and row<n and col>=0 and col<m and board[row][col]==word[index]) return true;
        return false;
    }
    bool helper(int index,int row, int col,int n ,int m, vector<vector<int>> &vis,string &word,vector<vector<char>> &board){
        if(index==word.size()) return true;
        
        int dr[]={-1,0,1,0,-1};
        
        for(int i=0;i<4;i++){
            int nrow=row+dr[i];
            int ncol=col+dr[i+1];
            
            if(check(index,nrow,ncol,n,m,board,word) and vis[nrow][ncol]==0){
                vis[nrow][ncol]=1;
                if(helper(index+1,nrow,ncol,n,m,vis,word,board)) return true;
                vis[nrow][ncol]=0;
            }
        }
        
        return false;
    }
public:
    bool isWordExist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    vis[i][j]=1;
                    if(helper(1,i,j,n,m,vis,word,board)) return true;
                    vis[i][j]=0;
                }
            }
        }
        return false;
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends