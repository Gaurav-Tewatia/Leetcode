class Solution {
public:

    bool issafe(vector<vector<bool>> vis,int xnew,int ynew,int n){
         for(int i=0;i<=ynew;i++){
             if(vis[xnew][i])
             return false;  
         }
         for(int i=0;i<=xnew;i++){
             if(vis[i][ynew])
             return false;
         }
         int i=xnew;
         int j=ynew;
         while(i>=0 and j<n){
             if(vis[i][j])
             return false;
             i--;
             j++;
         }

          i=xnew;
          j=ynew;
         while(i>=0 and j>=0){
             if(vis[i][j])
             return false;
             i--;
             j--;
         }

         return true;
    }

    void addsolution(vector<vector<string>>&ans,vector<string> temp,vector<vector<bool>> vis,string path){
        for(int i=0;i<vis.size();i++){
            path="";
            for(int j=0;j<vis[i].size();j++){
                if(vis[i][j]){
                    path.push_back('Q');
                }
                else
                path.push_back('.');
            }
            temp.push_back(path);
        }
        ans.push_back(temp);
    }

    void solve(vector<vector<string>> &ans,vector<string> temp,vector<vector<bool>> &vis,int n, int x, int y,string path){
        if(x==n){
            addsolution (ans,temp,vis,path);
            return;
        }
        
        for(int i=y;i<n;i++){
            if(issafe(vis,x,i,n)){
                vis[x][i]=true;
                
                solve(ans,temp,vis,n,x+1,0,path);
                vis[x][i]=false;
                
            }
            
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> temp;
        vector<vector<bool>> vis(n,vector<bool>(n,0));
        if(n==0)
        return ans;

        string path;

        solve(ans,temp,vis,n,0,0,path);

        return ans;
    }
};