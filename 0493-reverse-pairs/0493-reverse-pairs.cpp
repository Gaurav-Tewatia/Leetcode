class Solution {
    private:
    void merge(vector<int> &nums,int low,int mid,int high){
        int left=low,right=mid+1;
        vector<int> temp;
        int cnt=0;
        while(left<=mid and right<=high){
            if(nums[left]>nums[right]){
                temp.push_back(nums[right]);
                
                right++;
            }
            else{
                temp.push_back(nums[left++]);
            }
        }
        while(left<=mid) temp.push_back(nums[left++]);
        while(right<=high) temp.push_back(nums[right++]);
        
        for(int i=low;i<=high;i++){
            nums[i]=temp[i-low];
        }
        
    }
    int countpair(vector<int> &nums,int start,int mid,int end){
        int right=mid+1;
        int cnt=0;
        for(int i=start;i<=mid;i++){
            while(right<=end and nums[i]>(long long)(2*(long long)nums[right])) right++;
            cnt+=right-mid-1;
        }
        return cnt;
    }
    int mergesort(vector<int> &nums,int start,int end){
        if(start==end) return 0;
        
        long long mid=start+(end-start)/2;
        long long x=mergesort(nums,start,mid);
        long long y=mergesort(nums,mid+1,end);
        long long z=countpair(nums,start,mid,end);
         merge(nums,start,mid,end);
        
        return x+y+z;
    }
public:
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        return mergesort(nums,0,n-1);
    }
};