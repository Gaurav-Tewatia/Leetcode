class Solution {
public:
    
    bool found(string &path,vector<string> &wordDict,unordered_set<string> &mp){
        
       return mp.count(path);
        
    }
    bool solve(vector<string> &wordDict,string &s, int index,unordered_set<string>& mp,vector<int> &dp){
        
        if(index==s.size())
            return dp[index]=true;
        string path="";
        if(dp[index]!=-1)
        return dp[index];

        for(int i=index;i<s.size();i++){
            path.push_back(s[i]);
            if(found(path,wordDict,mp)){
                if(solve(wordDict,s,i+1,mp,dp))
                    return dp[i]=true;
            }
        }
        return dp[index]=false;
        
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        
        unordered_set<string> mp;
        for(auto c:wordDict){
            mp.insert(c);
        }
        int n=s.size();

        vector<int> dp(n+1,-1);
        
        return solve(wordDict,s,0,mp,dp);
    }
};