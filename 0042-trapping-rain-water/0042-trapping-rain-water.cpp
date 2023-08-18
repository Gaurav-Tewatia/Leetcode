class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int leftmax=0,rightmax=0;
        int left=0,right=n-1;
        int sum=0;
        while(left<=right){
            
            if(height[left]<=height[right]){
                if(leftmax<=height[left]) {
                    leftmax=height[left++];
                    continue;}
                sum+=leftmax-height[left++];
            }
            else{
                if(rightmax<=height[right]){
                    rightmax=height[right--];
                    continue;
                } 
                sum+=rightmax-height[right--];
            }
        }
        return sum;
    }
};