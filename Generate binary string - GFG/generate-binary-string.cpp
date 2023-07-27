//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{   private:
    void helper(int i,int n,string &s, string &str,vector<string> &ans){
        if(i==n){
            ans.push_back(str);
            return;
        }
        
        if(s[i]!='?') {
            str+=s[i];
            helper(i+1,n,s,str,ans);
            str.pop_back();
            return ;
        }
        str+='0';
        helper(i+1,n,s,str,ans);
        str.pop_back();
        str+='1';
        helper(i+1,n,s,str,ans);
         str.pop_back();
        
    }
	public:
		vector<string> generate_binary_string(string s)
		{
		    vector<string> ans;
		    string str;
		    int n=s.size();
		    helper(0,n,s,str,ans);
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string s;
	    cin >> s;
	    Solution ob;
	    vector<string> ans = ob.generate_binary_string(s);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    }
	return 0;
}
// } Driver Code Ends