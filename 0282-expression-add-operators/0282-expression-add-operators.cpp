class Solution {
    typedef long long ll;
    void helper(int i,int n,string &num,int target,ll cur,ll prev,string s,vector<string> &ans){
        if(i==n){
            if(cur==target)
            ans.push_back(s);
            return;
        }
        
        for(int j=i;j<n;j++){
            if(j>i and num[i]=='0') return;
            
            string temp=num.substr(i,j-i+1);
            long long digit=stol(temp);
            if(i==0){
                helper(j+1,n,num,target,digit,digit,s+temp,ans);
            }
            else{
                helper(j+1,n,num,target,cur+digit,digit,s+"+"+temp,ans);
                helper(j+1,n,num,target,cur-digit,-digit,s+"-"+temp,ans);
                helper(j+1,n,num,target,cur-prev+prev*digit,prev*digit,s+"*"+temp,ans);
            }
        }
    }
public:
    vector<string> addOperators(string num, int target) {
        int n=num.size();
        vector<string> ans;
        
        helper(0,n,num,target,0,0,"",ans);
        return ans;
    }
};