class Solution {
    private:
    void helper(int i,int k,int sum,vector<int> &v,vector<vector<int>> &ans){
        if(v.size()==k){
            if(sum==0)
            ans.push_back(v);
            return;
        }
        
        for(int j=i;j<=9;j++){
            if(j>sum) break;
            v.push_back(j);
            helper(j+1,k,sum-j,v,ans);
            v.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> v;
        helper(1,k,n,v,ans);
        return ans;
    }
};