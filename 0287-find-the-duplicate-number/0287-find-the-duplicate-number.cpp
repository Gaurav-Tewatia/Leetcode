class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> ans(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            ans[nums[i]]++;
        }
        int j;
        for(j=0;j<ans.size();j++){
            if(ans[j]>1)
                break;
        }
        return j;
    }
};