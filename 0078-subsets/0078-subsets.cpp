class Solution {
    private:
    void helper(int i,int n,vector<int>&nums,vector<int> &v,vector<vector<int>> &ans){
        if(i==n){
            ans.push_back(v);
            return;
        }
        
       v.push_back(nums[i]);
        helper(i+1,n,nums,v,ans);
        v.pop_back();
        helper(i+1,n,nums,v,ans);
        
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        int n=nums.size();
        helper(0,n,nums,v,ans);
        return ans;
    }
};