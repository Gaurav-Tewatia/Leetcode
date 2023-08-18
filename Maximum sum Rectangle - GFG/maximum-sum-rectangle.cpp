//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
    int kadane(int n,int *arr,int *start,int *finish){
        int sum=0,maxsum=INT_MIN;
        *finish=-1;
        int starti=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum<0){
                sum=0;
                starti=i+1;
            }
            else if(sum>maxsum){
                maxsum=sum;
                *start=starti;
                *finish=i;
            }
        }
        if(*finish!=-1) return maxsum;
        maxsum=arr[0];
        *start=0,*finish=0;
        for(int i=1;i<n;i++){
            if(arr[i]>maxsum){
                *start=i;
                *finish=i;
                maxsum=arr[i];
            }
        }
        return maxsum;
    }
  public:
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
        int left,right,start,finish;
        int row[R];
        int maxsum=INT_MIN;
        int lefi,righti,starti,finishi;
        for(left=0;left<C;left++){
            memset(row,0,sizeof(row));
            for(right=left;right<C;right++){
                
                for(int i=0;i<R;i++)
                row[i]+=M[i][right];
                
                int sum=kadane(R,row,&start,&finish);
                
                if(sum>maxsum){
                    maxsum=sum;
                    lefi=left;
                    righti=right;
                    starti=start;
                    finishi=finish;
                }
            }
        }
        
        return maxsum;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(N, M, v) << "\n";
    }
}
// } Driver Code Ends