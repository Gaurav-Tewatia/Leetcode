class Solution {
    private:
    bool check(int mid, vector<int> &nums,int k){
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum>mid){
                sum=nums[i];
                k--;
                if(k<=0)
                    return false;
            }
        }
        
        return true;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        
        while(low<=high){
            int mid=low+(high-low)/2;
            
            if(check(mid,nums,k))
                high=mid-1;
            else
                low=mid+1;
        }
        return low;
    }
};