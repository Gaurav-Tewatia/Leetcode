class Solution {
public:
    int trap(vector<int>& height) {
        // we can do it using extra 3N space 
        
        // but interviewer might gives a follow up question which asks to do it in O(1) space
        
        int maxleft=0,maxright=0;
        int n=height.size();
        int left=0,right=n-1;
        int res=0;
        while(left<=right){
            if(height[left]<=height[right]){
                if(height[left]>=maxleft) maxleft=height[left];
                else res+=maxleft-height[left];
                left++;
            }
            else{
                if(height[right]>=maxright) maxright=height[right];
                else res+=maxright-height[right];
                right--;
            }
        }
        return res;
    }
};