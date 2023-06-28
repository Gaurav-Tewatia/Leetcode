//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    
    private:
        bool check(int mid,int *arr,int d, int n){
            int ans=0;
            int day=1;
            for(int i=0;i<n;i++){
                ans+=arr[i];
                if(ans>mid){
                    ans=arr[i];
                    day++;
                    if(day>d) return false;
                }
            }
            return true;
        }
  public:
    int leastWeightCapacity(int arr[], int N, int D) {
        int low=*max_element(arr,arr+N);
        int high=0;
        for(int i=0;i<N;i++){
            high+=arr[i];
        }
        
        while(low<=high){
            int mid=low+(high-low)/2;
            
            if(check(mid,arr,D,N))
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
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}
// } Driver Code Ends