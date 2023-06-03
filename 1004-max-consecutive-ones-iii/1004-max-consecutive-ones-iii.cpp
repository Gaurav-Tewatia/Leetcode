class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0,maxi=0;
        
        int n=nums.size();
        while(j<n){
            if(nums[j]==0)
                k--;
            if(k==0){
                maxi=max(maxi,j-i+1);
            }
            if(k<0){
                while(k<0){
                    if(nums[i]==0)
                        k++;
                    i++;
                }
            }
            maxi=max(maxi,j-i+1);
            j++;
            
        }
        return maxi;
        
    }
};