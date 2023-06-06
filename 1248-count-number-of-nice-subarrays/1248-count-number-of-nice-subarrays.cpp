class Solution {
public:
    int atmost(vector<int> &nums,int k){
         int i=0,j=0,sum=0,n=nums.size();
        
        while(j<n){
            if(nums[j]%2!=0)
            {
                k--;
                while(k<0){
                    if(nums[i]%2!=0)
                        k++;
                    i++;
                }
          
            }
            sum+=j-i+1;
            j++;
            
        }
        return sum;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
       return atmost(nums,k)-atmost(nums,k-1);
    }
};