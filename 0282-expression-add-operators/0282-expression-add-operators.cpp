class Solution {
    private:
    void helper(int i,int n,string &num,string s,vector<string> &ans,long long cursum,long long prevnum,int target){
        if(i==n){
            if(cursum==target) ans.push_back(s);
            
            return;
        }
        
        for(int j=i;j<n;j++){
            
            //checking for leading zeros
            
            if(j>i and num[i]=='0') return;    //"1203" -> 12+03. here 0 is leading
            
            string str=num.substr(i,j-i+1);
            long long number=stol(str);
            if(i==0){
                helper(j+1,n,num,s+str,ans,number,number,target);
            }
            else{
                helper(j+1,n,num,s+"+"+str,ans,cursum+number,number,target);
                helper(j+1,n,num,s+"-"+str,ans,cursum-number,-number,target);
                helper(j+1,n,num,s+"*"+str,ans,cursum-prevnum+prevnum*number,prevnum*number,target);
            }
        }
    }
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        int n=num.size();
        helper(0,n,num,"",ans,0,0,target);
        return ans;
    }
};