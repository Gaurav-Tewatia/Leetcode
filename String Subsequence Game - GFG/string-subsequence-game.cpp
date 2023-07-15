//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    private:
    set<char> ch={'a','e','i','o','u'};
    void helper(int i, int n, set<string> &ans,string &s,string &S){
        if(i==n){
            if(ch.find(s.back())==ch.end() and s.size()!=0)
            ans.insert(s);
            return;
        }
            if(s.size()==0){
                if(ch.count(S[i])){
                    s.push_back(S[i]);
                    helper(i+1,n,ans,s,S);
                    s.pop_back();
                    helper(i+1,n,ans,s,S);
                }
                else{
                    helper(i+1,n,ans,s,S);
                }
            }
            else{
                s.push_back(S[i]);
                helper(i+1,n,ans,s,S);
                s.pop_back();
                helper(i+1,n,ans,s,S);
            }
    }
  public:
    set<string> allPossibleSubsequences(string S) {
        set<string> ans;
        int n=S.size();
        string s="";
        helper(0,n,ans,s,S);
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        set<string> ans = ob.allPossibleSubsequences(S);
        if (ans.size() == 0)
            cout << -1 << endl;
        else {
            for (auto i : ans) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// } Driver Code Ends