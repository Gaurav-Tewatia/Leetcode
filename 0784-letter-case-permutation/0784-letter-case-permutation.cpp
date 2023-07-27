class Solution {
    private:
    void helper(int i,int n,string &s,string &str,vector<string> &ans){
        if(i==n){
            ans.push_back(str);
            return;
        }
        
        if(isdigit(s[i])){
            str.push_back(s[i]);
            helper(i+1,n,s,str,ans);
            str.pop_back();
        } 
        else{str.push_back(toupper(s[i]));
        helper(i+1,n,s,str,ans);
        str.pop_back();
             str.push_back(tolower(s[i]));
             helper(i+1,n,s,str,ans);
             str.pop_back();
        }
        
    }
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        string str;
        int n=s.size();
        helper(0,n,s,str,ans);
        return ans;
    }
};