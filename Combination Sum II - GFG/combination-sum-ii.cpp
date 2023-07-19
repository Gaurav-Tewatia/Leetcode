//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    private:
    void helper(int i,int n,vector<int> &candidates,int target,vector<int> &v, vector<vector<int>> &ans){
        if(target==0){
            ans.push_back(v);
            return;
        }
        
        for(int j=i;j<n;j++){
            if(j!=i and (candidates[j]==candidates[j-1])) continue;
            if(candidates[j]>target)break;
            v.push_back(candidates[j]);
            helper(j+1,n,candidates,target-candidates[j],v,ans);
            v.pop_back();
        }
    }
  public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        int n=candidates.size();
        sort(candidates.begin(),candidates.end());
        helper(0,n,candidates,target,v,ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {

    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> candidates(n);
        for (int i = 0; i < n; ++i) {
            cin >> candidates[i];
        }
        // char marker;
        // cin >> marker;

        Solution obj;

        vector<vector<int>> comb = obj.combinationSum2(candidates, k);
        sort(comb.begin(), comb.end());
        cout << "[ ";
        for (int i = 0; i < comb.size(); i++) {
            cout << "[ ";
            for (int j = 0; j < comb[i].size(); j++) {
                cout << comb[i][j] << " ";
            }
            cout << "]";
        }
        cout << " ]\n";

        // cout << "\n~\n";
    }
    fclose(stdout);
    return 0;
}

// } Driver Code Ends