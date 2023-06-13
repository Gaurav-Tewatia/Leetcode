//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string minWindow(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();
        
        int start=0,end=INT_MAX; //start=starting point of the req string, end=length of the req string
        
        int i=0;
        
        for(int j=0;j<n;j++){
            if(str1[j]==str2[i]) i++;
            if(i==m){                   //if our str2 is complete then we have to find the start and the length
                int l1=j,l2=i-1;
                while(l2>=0){
                    if(str1[l1--]==str2[l2])
                    l2--;
                }
                
                if(j-l1+1<end)          //this is to make sure that we have a lenght
                end=j-(start=l1+1)+1;       //sinche inside while loop our l1 has gone 1 less than the index we want our start becomes l1+1
            }
        }
        return end==INT_MAX?"":str1.substr(start,end);      //substr(starting index,length of the substring)
    }
};


//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string str1, str2;
        cin >> str1 >> str2;

        Solution obj;
        cout << obj.minWindow(str1, str2) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends