class Solution {
    private:
    void helper(int i,int n,vector<int> candidate,int target,vector<vector<int>> &ans,
               vector<int> &v){
        if(target==0){
            ans.push_back(v);
            return;
        }
        for(int idx=i;idx<n;idx++){
            if(idx>i and candidate[idx]==candidate[idx-1]) continue;
            if(candidate[idx]>target) break;
            v.push_back(candidate[idx]);
            helper(idx+1,n,candidate,target-candidate[idx],ans,v);
            v.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int> > ans;
        vector<int> v;
        sort(candidates.begin(),candidates.end());
        int n=candidates.size();
        
        helper(0,n,candidates,target,ans,v);
        return ans;
    }
};