//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    
    private:
        bool check(int mid, vector<int> &nums, int k){
            int ans=0;
            int n=nums.size();
            
            for(int i=0;i<n;i++){
                ans+=nums[i]/mid+(nums[i]%mid!=0);
                if(ans>k)
                return false;
            }
            return true;
            
        }
  public:
    int smallestDivisor(vector<int>& nums, int K) {

        if(nums.size()>K) return -1;
        int high=*max_element(begin(nums),end(nums));
        
        if(nums.size()==K) return high;
        int low=1;
            
        while(low<=high){
            int mid=low+(high-low)/2;
            
            if(check(mid,nums,K))
            high=mid-1;
            else
            low=mid+1;
        }
        return low;
    }
};


//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        int n, k;
        cin >> n >> k;
        vector<int> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];

        Solution obj;
        cout << obj.smallestDivisor(vec, k) << endl;
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends