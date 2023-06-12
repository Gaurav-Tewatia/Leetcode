class Solution {
public:
//    int atMost(vector<int>& A, int S) {
//     int i=0,j=0,count=0,sum=0;
//     int size=A.size();
//     if (S < 0)return 0;
    
//     while(j<size){
//         sum+=A[j];
//         while(sum>S ){
//             sum-=A[i];
//             i++;
//         }
//         count+=j-i+1;
//         j++;
//     }
//     return count;
// }

// int numSubarraysWithSum(vector<int>& A, int S) {
//      return atMost(A, S) - atMost(A, S - 1);

// }
    
    int solve(vector<int>&nums, int goal){
        int i=0,j=0,ans=0;
        if(goal<0)return 0;
        int n=nums.size();
        while(j<n){
            goal-=nums[j];
            while(goal<0){
                goal+=nums[i];
                i++;
            }
            ans+=j-i+1;
            j++;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return solve(nums,goal)-solve(nums,goal-1);
    }
};