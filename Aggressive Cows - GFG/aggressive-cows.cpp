//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    
    private:
        bool check(vector<int> &stalls,int mid,int k, int n){
            int cow=1,dis=0;
            int last_placed=stalls[0];
            for(int i=1;i<n;i++){
                 dis=stalls[i]-last_placed;
                if(dis>=mid){
                    cow++;
                     if(cow>=k)
                        return true;
                        
                    
                    last_placed=stalls[i];
                   
                }
            }
            return false;
        }
public:

    int solve(int n, int k, vector<int> &stalls) {
    
        int low=1;
        int high=*max_element(stalls.begin(),stalls.end())-*min_element(stalls.begin(),stalls.end());
        sort(stalls.begin(),stalls.end());
        while(low<=high){
            int mid=low+(high-low)/2;
            
            if(check(stalls,mid,k,n))
            low=mid+1;
            else
            high=mid-1;
        }
        return high;
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

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends