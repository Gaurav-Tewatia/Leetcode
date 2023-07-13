//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int mod =1e9+7;
  long long power(long long x, long long y){
      if(y==0) return 1;
      long long ans=power(x,y/2);
      ans*=ans;
      ans%=mod;
      if(y%2) ans*=x;
      ans%=mod;
      return ans;
  }
    int countGoodNumbers(long long N) {
        long long even =N/2+N%2;
        long long odd=N/2;
        return power(5,even)*power(4,odd)%mod;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        cin >> N;
        Solution ob;

        cout << ob.countGoodNumbers(N) << endl;
    }
}
// } Driver Code Ends