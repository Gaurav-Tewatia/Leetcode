//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

//User function template for C++
//User function template for C++

//User function template for C++
class Solution{
    private:
     int find(vector<int> &mat,int low,int high,int x){
         
         while(low<=high){
             int mid=low+(high-low)/2;
             if(mat[mid]==x) return mid;
             else if(mat[mid]>x)
             high=mid-1;
             else
             low=mid+1;
         }
         
         return -1;
     }
public:	
	int matSearch (vector <vector <int>> &mat, int N, int M, int X)
	{
	   for(int i=0;i<N;i++){
	       
	       int col=find(mat[i],0,M-1,X);
	       if(col!=-1)
	       return 1;
	   }
	   return 0;
	}
};


//{ Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        vector <vector <int>> arr (n, vector <int> (m));
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                cin >> arr[i][j];
                
        int x; cin >> x;
        Solution ob;
        cout << ob.matSearch (arr, n, m, x) << endl;
    }
}
// } Driver Code Ends