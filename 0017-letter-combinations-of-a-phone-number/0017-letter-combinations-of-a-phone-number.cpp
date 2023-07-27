class Solution {
    void helper(int i,int n, string &digits,vector<string> &letters,string &path,vector<string> &ans){
        if(i==n){
            ans.push_back(path);
            return;
        }
        int digit=digits[i]-'0';
        if(digit==0 or digit==1)
            helper(i+1,n,digits,letters,path,ans);
        else{
            string temp=letters[digit];
            int sz=temp.size();
            for(int j=0;j<sz;j++){
                path+=temp[j];
                helper(i+1,n,digits,letters,path,ans);
                path.pop_back();
            }
        }
        
        
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};
        vector<string> letter{""," ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans;
        
        int n=digits.size();
        string path;
        helper(0,n,digits,letter,path,ans);
        return ans;
    }
};