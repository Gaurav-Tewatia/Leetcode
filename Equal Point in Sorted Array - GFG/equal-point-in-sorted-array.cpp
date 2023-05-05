//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

int findEqualPoint(int arr[], int n) ;

int main()
{
	int t; cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n]={0};
		for(int i = 0; i < n; i++)
		cin>>arr[i];
		
		cout<< findEqualPoint(arr, n) <<endl;
	}
	
	return 0;
}

// } Driver Code Ends


int findEqualPoint(int arr[], int n) 
{
    vector<pair<int,int>> ans;
    for(int i=0;i<n;i++){
        if(i==0 or arr[i]!=arr[i-1])
        ans.push_back({arr[i],i});
    }
    int s=ans.size();
    if(s%2==0)
    return -1;
    else
    return ans[s/2].second;
}