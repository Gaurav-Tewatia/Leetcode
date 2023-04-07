//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int addMinChar(string str){    
        //code here
        int n=str.size();
        int i=0;
        int j=n-1;
        while(i<=j)
        {
            if(str[i]==str[j])
            {
                i++;
                j--;
            }
            else
            {
                break;
            }
        }
        if(i>=j)
        {
            return 0;
        }
        int lo=0;
        int hi=n-1;
        int count=0;
        while(lo<=hi)
        {
            if(str[lo]==str[hi])
            {
                lo++;
                hi--;
            }
            else
            {
                count++;
                lo=0;
                hi=str.size()-1-count;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.


int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin >> str;
        
        Solution ob;
        cout << ob.addMinChar(str) << endl;
    }
    return 0; 
} 
// } Driver Code Ends