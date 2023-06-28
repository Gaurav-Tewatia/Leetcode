//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
    private:
    
        bool check(int mid, vector<int> &day,int k, int m){
            int cnt=k;
            int n=day.size();
            for(int i=0;i<n;i++){
                if(day[i]<=mid){
                    cnt--;
                    if(cnt==0){
                        cnt=k;
                        m--;
                        if(m==0)
                        return true;
                    }
                    
                }else
                cnt=k;
            }
            
            return false;
        }
  public:
    int solve(int M, int K, vector<int> &bloomDay){
        if(M*K>bloomDay.size()) return -1;
        
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(begin(bloomDay),end(bloomDay));
        
        while(low<=high){
            int mid=low+(high-low)/2;
            
            if(check(mid,bloomDay,K,M))
            high=mid-1;
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
        int m, k;
    cin >> m >> k;
    string s;
    getline(cin, s);
    getline(cin, s);
    int n = s.length();
    int num = 0;
    bool f = 0;
    vector<int> bloomDay;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == ' ')
      {
        if (!f)
          continue;
        bloomDay.push_back(num);
        num = 0;
        f = 0;
      }
      else
      {
        num = (num * 10) + (s[i] - '0');
        f = 1;
      }
    }
    if (f)
    {
      bloomDay.push_back(num);
    }
    Solution obj;
    cout<<obj.solve(m, k, bloomDay)<<endl;
    }
    return 0;
}
// } Driver Code Ends