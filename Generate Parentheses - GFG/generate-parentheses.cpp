//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    private: 
    void fnc(int n, vector<string> &ans, string &s,int in, int out){
        if(out==n){
            ans.push_back(s);
            return;
        }
        if(in<n){
            s+='(';
            fnc(n,ans,s,in+1,out);
            s.pop_back();
        }
        if(out<in){
            s+=')';
            fnc(n,ans,s,in,out+1);
            s.pop_back();
        }
    }
    public:
    vector<string> AllParenthesis(int n) 
    {
        vector<string> ans;
        string s="";
        fnc(n,ans,s,0,0);
        return ans;
    }
};

//{ Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 

// } Driver Code Ends