class Solution {
    void helper(int i,int n, string &s, vector<string> &wordDict,unordered_set<string> &st,vector<string> &str,vector<string> &ans){
        if(i==n){
            
            string tmp;
            for(auto it:str) tmp+=it+" ";
            tmp.pop_back();
            ans.push_back(tmp);
            
            return;
        }
        
        for(int j=i;j<n;j++){
            string temp=s.substr(i,j-i+1);
            if(st.count(temp)){
                str.push_back(temp);

                helper(j+1,n,s,wordDict,st,str,ans);
                str.pop_back();
                
            }
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(),wordDict.end());
        int n=s.size();
        vector<string> ans;
        vector<string> str;
        helper(0,n,s,wordDict,st,str,ans);
        return ans;
    }
};