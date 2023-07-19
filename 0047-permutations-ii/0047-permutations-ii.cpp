class Solution {
    private:
    void helper(int i, int n, vector<int> nums,vector<int> &v,vector<vector<int> > &ans){
        if(i==n){
            ans.push_back(v);
            return;
        }
        
        for(int idx=i;idx<n;idx++){
            if(idx!=i and (nums[idx]==nums[idx-1] or nums[idx]==nums[i])) continue;
            swap(nums[idx],nums[i]);
            v.push_back(nums[i]);
            helper(i+1,n,nums,v,ans);
           // swap(nums[idx],nums[i]);
            v.pop_back();
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        helper(0,n,nums,v,ans);
        return ans;
    }
};