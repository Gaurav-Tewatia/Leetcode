//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


int KthMissingElement(int a[], int n, int k);


int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        
        cout << KthMissingElement(a, n, k) << endl;
    
    }
    return 0;
}

// } Driver Code Ends


int KthMissingElement(int a[], int n, int k)
{
    int low=0,high=n-1;
    // for(int i=0;i<n;i++){
    //     low=min(low,a[i]);
    //     high=max(high,a[i]);
    // }
    
    
    int mid=0;
   while(low<=high){
        mid=low+(high-low)/2;
        
       int missing=a[mid]-(a[0]+mid);
       
       if(missing<k)
       low=mid+1;
       else
       high=mid-1;
   }
   if(high==n-1) return -1;
   return k+a[0]+high;
}