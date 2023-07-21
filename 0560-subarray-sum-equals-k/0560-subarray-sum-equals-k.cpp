class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int sum=0,cnt=0;
        mp.insert({0,1});
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int rem=sum-k;
            if(mp.find(rem)!=mp.end())
                cnt+=mp[rem];
            mp[sum]++;
            
        }
        return cnt;
    }
};