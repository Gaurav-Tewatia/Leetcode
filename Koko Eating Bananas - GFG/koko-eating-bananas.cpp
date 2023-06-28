//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
    private:
         bool check(int mid, vector<int> &piles,int h, int n){
             int eaten=0;
             for(int i=0;i<n;i++){
                 eaten+=(piles[i]/mid)+(piles[i]%mid!=0);
                 if(eaten>h)
                 return false;
             }
             return true;
         }
  public:
    int Solve(int N, vector<int>& piles, int H) {
        int high=*max_element(piles.begin(),piles.end());
        int low=1;
        
        while(low<=high){
            int mid=low+(high-low)/2;
            
            if(check(mid,piles,H,N)){
                high=mid-1;
            }
            else
            low=mid+1;
        }
        return low;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends