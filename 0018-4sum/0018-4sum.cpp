class Solution {
    private: typedef long long ll;
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<n-3;i++){
            if(i>0 and nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<n-2;j++){
                if(j>i+1 and nums[j]==nums[j-1]) continue;
                int k=j+1,l=n-1;
                while(k<l){
                    long long sum=(long long)(nums[i])+(ll)(nums[j])+(ll)(nums[k])+(ll)(nums[l]);
                    if(sum<target){
                        k++;
                    }
                    else if(sum>target) l--;
                    else{
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        k++;
                        l--;
                        while(k<l and nums[k]==nums[k-1]) k++;
                        while(k<l and nums[l]==nums[l+1]) l--;
                    }
                }
            }
        }
        return ans;
    }
};