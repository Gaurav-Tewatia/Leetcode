class Solution {
    private:
    void helper(int i,int n, int target, vector<int> &candidates,vector<int> &v,
               vector<vector<int>> &ans){
        if(i==n){
            if(target==0)
                ans.push_back(v);
            
            return;
        }
        
        if(candidates[i]<=target){
            v.push_back(candidates[i]);
            helper(i,n,target-candidates[i],candidates,v,ans);
            v.pop_back();
        }
        
        helper(i+1,n,target,candidates,v,ans);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> v;
        int n=candidates.size();
        vector<vector<int>> ans;
        helper(0,n,target,candidates,v,ans);
        return ans;
    }
};