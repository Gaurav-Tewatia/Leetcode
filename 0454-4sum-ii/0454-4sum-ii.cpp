class Solution {
    private: typedef long long ll;
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
       
        unordered_map<int,int> mp;
        for(auto it:nums1){
            for(auto it1:nums2) mp[it+it1]++;
        }
        
        int cnt=0;
        for(auto it:nums3){
            for(auto it2:nums4){
                if(mp.count(0-it-it2)) cnt+=mp[0-it-it2];
            }
        }
        return cnt;
    }
};