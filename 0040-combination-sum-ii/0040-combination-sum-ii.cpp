class Solution {
    private:
    void helper(int i,int n,vector<int> &candidates,int target,vector<int> &v,vector<vector<int>> &ans){
        if(target==0){
            ans.push_back(v);
            return;
        }
        
        for(int j=i;j<n;j++){
            if(j!=i and candidates[j]==candidates[j-1]) continue;
            if(candidates[j]>target) break;
            v.push_back(candidates[j]);
            helper(j+1,n,candidates,target-candidates[j],v,ans);
                v.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> v;
        int n=candidates.size();
        helper(0,n,candidates,target,v,ans);
        return ans;
    }
};