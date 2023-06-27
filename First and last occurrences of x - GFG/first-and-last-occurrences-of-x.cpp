//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

int firstoccurence(int *arr,int n, int k){
    int low=0,high=n-1;
    int ans=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        
        if(arr[mid]==k){
            ans=mid;
            high=mid-1;
        }
        else if(arr[mid]>k)
        high=mid-1;
        else
        low=mid+1;
        
    }
    
    return ans;
}


int lastoccurence(int *arr,int n, int k){
     int low=0,high=n-1;
    int ans=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        
        if(arr[mid]==k){
            ans=mid;
            low=mid+1;
        }
        else if(arr[mid]>k)
        high=mid-1;
        else
        low=mid+1;
        
    }
    
    return ans;
}

vector<int> find(int arr[], int n , int x )
{
    int low=0,high=n-1;
    int first=-1;
    int last=-1;
    
    first=firstoccurence(arr,n,x);
    last=lastoccurence(arr,n,x);
    
    vector<int> ans({first,last});
    return ans;
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends