class Solution {
    private:
    void helper(int i,int n,vector<int> &s, vector<vector<int>> &ans,vector<int> &nums){
        if(i==n){
            ans.push_back(s);
            return;
        } 
        helper(i+1,n,s,ans,nums);
        s.push_back(nums[i]);
        helper(i+1,n,s,ans,nums);
        s.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> s;
        int n=nums.size();
        helper(0,n,s,ans,nums);
        return ans;
    }
};