class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i;
        int n=nums.size();
        for( i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1])
                break;
        }
        if(i==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        
        int index=i;
        
        for(int j=n-1;j>index;j--){
            if(nums[j]>nums[index]){
                swap(nums[j],nums[index]);
                break;
            }
        }
        reverse(nums.begin()+index+1,nums.end());
        return;
    }
};