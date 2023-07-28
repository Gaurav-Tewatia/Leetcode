class Solution {
    int helper(int i,int m,string &str,unordered_multiset<string> &st,vector<int> &dp){
        if(i==m ){
            return dp[i]=0;
        }
        if(dp[i]!=-1) return dp[i];
        int count=INT_MIN;
        for(int j=i;j<m;j++){
            if(st.count(str.substr(i,j-i+1))){
                count=max(count,helper(j+1,m,str,st,dp)+1);
            }
        }
        return dp[i]=count;
    }
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        
        vector<string> ans;
        int n=words.size();
        unordered_multiset<string> st(words.begin(),words.end());
        
        for(int i=0;i<n;i++){
            string str=words[i];
            int m=str.size();
            vector<int> dp(m+1,-1);
            
            int cnt=helper(0,m,str,st,dp);
            if(cnt>=2) ans.push_back(str);
        }
        return ans;
    }
};