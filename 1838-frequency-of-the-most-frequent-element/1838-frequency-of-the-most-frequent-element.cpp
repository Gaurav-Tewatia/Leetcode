class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        long long sum=0;
        int i=0,j=0;
        int maxlen=-1;
        while(j<n){
            sum+=nums[j];
            
            while(i<j and 1ll*nums[j]*(j-i+1)>sum+k) sum-=nums[i++];
            
            maxlen=max(maxlen,j-i+1);
            j++;
        }
        return maxlen;
    }
};