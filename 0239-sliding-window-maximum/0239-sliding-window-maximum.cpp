class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<k;i++){
            pq.push({nums[i],i});
        }
        vector<int> ans;
        ans.push_back(pq.top().first);
        int n=nums.size();
        for(int i=k;i<n;i++){
            while(i-pq.top().second>=k and !pq.empty())
                pq.pop();
            pq.push({nums[i],i});
            
            ans.push_back(pq.top().first);
        }
        
        return ans;
    }
};