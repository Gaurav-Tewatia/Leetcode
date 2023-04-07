class Solution {
public:

    bool possible(string path){
        int n=path.size()-1;
        int s=0;
        while(s<n){
            if(path[s]!=path[n])
            return false;
            s++;
            n--;
        }
        return true;
    }

    void solve(vector<vector<string> >& ans, vector<string> temp, string path, string s,int index){
        if(index==s.size()){
            ans.push_back(temp);
            return;
        }

        path="";
           for(int i=index;i<s.size();i++){
               path.push_back(s[i]);

               if(possible(path)){
                   temp.push_back(path);
                   solve(ans,temp,path,s,i+1);
                   temp.pop_back();
               }
           }
        
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        string path;
        solve(ans,temp,path,s,0);

        return ans;

    }
};