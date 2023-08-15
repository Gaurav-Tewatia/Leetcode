//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      sort(arr,arr+N);
      int lastsmall=INT_MIN;
      int maxi=0;
      int cnt=0;
      for(int i=0;i<N;i++){
          if(arr[i]-1==lastsmall){
              cnt++;
              lastsmall=arr[i];
          }
          else if(arr[i]!=lastsmall){
              cnt=1;
              lastsmall=arr[i];
          }
          maxi=max(maxi,cnt);
      }
      return maxi;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends