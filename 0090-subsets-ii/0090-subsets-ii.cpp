class Solution {
    private:
    void helper(int i,int n, vector<int> &nums,vector<int> &v,vector<vector<int>> &ans){
        ans.push_back(v);
        
        for(int j=i;j<n;j++){
            if(j!=i and nums[j]==nums[j-1]) continue;
            v.push_back(nums[j]);
            helper(j+1,n,nums,v,ans);
            v.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> v;
        int n=nums.size();
        helper(0,n,nums,v,ans);
        return ans;
    }
};