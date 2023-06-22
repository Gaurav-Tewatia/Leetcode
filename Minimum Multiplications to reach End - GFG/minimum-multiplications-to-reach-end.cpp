//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int mod=100000;
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        queue<pair<int,int>>pq;
        pq.push({start,0});
        vector<int>dis(100000,1e9);
        dis[start]=0;
        while(!pq.empty()){
            int node=pq.front().first;
            int steps=pq.front().second;
            pq.pop();
            
            
            
            for(auto c:arr){
                int num=(node*c)%mod;
                
                if(num==end)
                return steps+1;
               if(dis[num]>steps+1){
                   dis[num]=steps+1;
                   pq.push({num,steps+1});
               }
                
            }
        }
        
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends