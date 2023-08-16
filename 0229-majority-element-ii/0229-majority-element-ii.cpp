class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ele=INT_MIN;
        int ele2=INT_MIN;
        int cnt1=0,cnt2=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(cnt1==0 and ele2!=nums[i]){
                cnt1=1;
                ele=nums[i];
            }
            else if(cnt2==0 and ele!=nums[i]){
                cnt2=1;
                ele2=nums[i];
            }
            else if(ele==nums[i]) cnt1++;
            else if(ele2==nums[i]) cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }
        
        vector<int> ans;
        cnt1=0,cnt2=0;
        for(int i=0;i<nums.size();i++){
            if(ele==nums[i]) cnt1++;
            if(ele2==nums[i]) cnt2++;
        }
         int mini = int(n / 3) + 1;
        if(cnt1>=mini) ans.push_back(ele);
        if(cnt2>=mini) ans.push_back(ele2);
        return ans;
    }
};