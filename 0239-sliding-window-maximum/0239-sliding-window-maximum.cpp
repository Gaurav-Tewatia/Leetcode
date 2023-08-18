class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(!dq.empty() and dq.front()==i-k) dq.pop_front();  //this is to maintain the window size
            while(!dq.empty() and nums[dq.back()]<nums[i]) dq.pop_back();  //this is to store the largest at front
            dq.push_back(i);
            if(i>=k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};