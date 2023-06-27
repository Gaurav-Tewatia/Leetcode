//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends


pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    sort(arr,arr+n);
    pair<int,int> ans{-1,-1};
    
    int low=0;
    int high=n-1;
    
    while(low<=high){
        int mid=low+(high-low)/2;
        
        if(arr[mid]==x){
            ans.first=ans.second=arr[mid];
            return ans;
        }
        else if(arr[mid]>x){
            ans.second=arr[mid];
            high=mid-1;
        }
        else{
            ans.first=arr[mid];
            low=mid+1;
        }
        
    }
   
    return ans;
}