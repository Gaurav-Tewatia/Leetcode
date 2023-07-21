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
    {   sort(arr,arr+N);
        if(N==0) return 0;
        int maxlen=1,cnt=0;
        int prev=INT_MIN;
        for(int i=0;i<N;i++){
            if(arr[i]-1==prev){
                prev=arr[i];
                cnt++;
            }else if(arr[i]!=prev){
                cnt=1;
                prev=arr[i];
            }
            maxlen=max(maxlen,cnt);
        }
        
        return maxlen;
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