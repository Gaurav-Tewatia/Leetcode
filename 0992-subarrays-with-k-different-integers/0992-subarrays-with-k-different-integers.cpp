class Solution {
    private:
    
    int solve(vector<int>&nums,int k){
        unordered_map<int,int> mp;
        int n=nums.size();
        int i=0,j=0;
        int ans=0;
        while(j<n){
            if(!mp[nums[j]]++)
                k--;
            while(k<0){
                
                if(--mp[nums[i]]==0)
                    k++;
                i++;
            }
            ans+=j-i+1;
            j++;
        }
        return ans;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);
    }
};