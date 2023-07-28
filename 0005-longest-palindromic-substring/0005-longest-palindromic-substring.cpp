
class Solution {
    bool check(int i,int j,string &s){
        while(i<j){
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }
    int helper(int i,int n,string &s,vector<int> &dp){
        if(i==n) return dp[i]=0;;
        
        if(dp[i]!=-1) return dp[i];
        int cnt=INT_MIN;
        for(int j=i;j<n;j++){
            if(check(i,j,s)){
                cnt=max(j-i+1,helper(j+1,n,s,dp));
            }
        }
        
       cnt=max(cnt,helper(i+1,n,s,dp));
               return dp[i]=cnt;
    }
public:
    string longestPalindrome(string s) {
        int n=s.size();
        string str;
        vector<int> dp(n+1,-1);
        int windowsize=helper(0,n,s,dp);
        int i=0,j=windowsize-1;
        while(j<n){
            if(!check(i,j,s)){
                j++;
                i++;
            }else{
                break;
            }
        }
        for(int k=i;k<=j;k++) str+=s[k];
        return str;
    }
};