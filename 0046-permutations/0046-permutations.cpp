class Solution {
    void helper(int idx,int n,vector<int> &nums,vector<int> &v, vector<vector<int>> &ans){
    if(idx==n){
        ans.push_back(v);
        return;
    }
        for(int i=idx;i<n;i++ ){
            swap(nums[i],nums[idx]);
            v.push_back(nums[idx]);
            helper(idx+1,n,nums,v,ans);
            swap(nums[i],nums[idx]);
            v.pop_back();
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        int n=nums.size();
        helper(0,n,nums,v,ans);
        return ans;
    }
};