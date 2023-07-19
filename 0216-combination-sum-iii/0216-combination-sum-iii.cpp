class Solution {
    private:
    void helper(int i,int n,int k,vector<int> &v,vector<vector<int>> &ans){
        if(v.size()==k){
            if(n==0) ans.push_back(v);
            
            return;
        }
        for(int j=i;j<=9;j++){
            if(j<=n){
                n-=j;
                v.push_back(j);
                helper(j+1,n,k,v,ans);
                v.pop_back();
                n+=j;
            }
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> v;
        helper(1,n,k,v,ans);
        return ans;
    }
};