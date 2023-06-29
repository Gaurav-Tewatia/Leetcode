//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
    private:
    bool check(double mid, vector<int> &stations, int k){
        int n=stations.size();
        for(int i=1;i<n;i++){
            int diff=stations[i]-stations[i-1];
            if(diff>mid){
                int inserted=(diff)/mid;
                k-=inserted;
                if(k<0)
                return false;
            }
        }
        return true;
    }
  public:
    double findSmallestMaxDist(vector<int> &stations, int K){
      sort(stations.begin(),stations.end());
      int n=stations.size();
      double high=stations[n-1]-stations[0];
      double low=0;
      
      while(high-low>1e-5){
          double mid=(high+low)/2;
          
          if(check(mid,stations,K))
          high=mid;
          else
          low=mid;
      }
    //   cout<<setprecision(2);
      return low+0.00001;
    }
};


//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<int> stations(n);
    for (int i = 0; i < n; i++)
    {
      cin >> stations[i];
    }
    int k;
    cin >> k;
    Solution obj;
    cout << fixed << setprecision(2) << obj.findSmallestMaxDist(stations, k) << endl;
  }
  return 0;
}
// } Driver Code Ends