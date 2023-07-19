//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    private:
    void helper(int i,int n,vector<int> &nums,vector<int> &v, vector<vector<int>> &ans){
        ans.push_back(v);
        
        for(int j=i;j<n;j++){
            if(j!=i and nums[j]==nums[j-1]) continue;
            v.push_back(nums[j]);
            helper(j+1,n,nums,v,ans);
            v.pop_back();
        }
    }

  public:
    vector<vector<int>> printUniqueSubsets(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int> > ans;
        vector<int> v;
        int n=nums.size();
        helper(0,n,nums,v,ans);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        // char marker;
        // cin >> marker;

        Solution obj;
        vector<vector<int>> ans = obj.printUniqueSubsets(nums);
        sort(ans.begin(), ans.end());
        //   printAns(ans);
        cout << "[ ";
        for (int i = 0; i < ans.size(); i++) {
            cout << "[ ";
            for (int j = 0; j < ans[i].size(); j++) cout << ans[i][j] << " ";
            cout << "]";
        }
        cout << " ]\n";

        // cout<< "~\n";
    }

    return 0;
}

// } Driver Code Ends