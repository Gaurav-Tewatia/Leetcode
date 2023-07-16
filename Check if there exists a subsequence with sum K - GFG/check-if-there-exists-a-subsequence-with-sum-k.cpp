//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    private:
        bool helper(int i, int n, vector<int> &arr, int k){
            if(i==n){
                if(k==0)
                return true;
                else 
                return false;
            }
            
            if(k==0) return true;
            if(arr[i]<=k)
            {
                return helper(i+1,n,arr,k-arr[i]) or helper(i+1,n,arr,k);
            }
            else
            return helper(i+1,n,arr,k);
            
            
        }
    public:
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        
        return helper(0,n,arr,k);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> arr;
        
        for(int i=0; i<n; ++i){
            int x; cin>>x;
            arr.push_back(x);
        }
        
        Solution obj;
        bool ans = obj.checkSubsequenceSum(n, arr, k);
        cout<<( ans ? "Yes" : "No")<<"\n";
    }
    return 0;
}
// } Driver Code Ends