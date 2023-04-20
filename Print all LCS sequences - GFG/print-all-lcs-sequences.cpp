//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	    vector<string> ans;
	    int lcs = 0;
		// int iters = 0;
	    void helper(int i,int j,string &s, string &t, string &cur,vector<vector<int>> &dp, vector<vector<unordered_set<string>>> &done){
	    //    cout << i << ' ' << j << ' ' << cur << '\n';
		   if (done[i][j].find(cur) != done[i][j].end())
		   	return;
			done[i][j].insert(cur);
	        if(i>0 and j>0){
	            if(s[i-1]==t[j-1]){
	                cur.push_back(s[i - 1]);
	                helper(i-1,j-1,s,t,cur,dp, done);
	                cur.pop_back();
	            }
	            if(dp[i][j]==dp[i - 1][j]){
                    helper(i - 1, j, s, t, cur, dp, done);
	            }
	            if (dp[i][j] == dp[i][j - 1]) {
	                helper(i, j - 1, s, t, cur, dp, done);
	            }
	        }
	        if (lcs != cur.length())
	            return;
	        reverse(begin(cur), end(cur));
	        ans.push_back(cur);
	        reverse(begin(cur), end(cur));
	    }
		vector<string> all_longest_common_subsequences(string s, string t)
		{
		    int n=s.size();
		    int m=t.size();
		    
		    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
			vector<vector<unordered_set<string>>> done(n + 1, vector<unordered_set<string>>(m + 1, unordered_set<string>()));
		    
		    for(int i=0;i<=n;i++){
		        for(int j=0;j<=m;j++){
		            if(i==0 or j==0)
		            dp[i][j]=0;
		            else if(s[i-1]==t[j-1])
		            dp[i][j]=1+dp[i-1][j-1];
		            else
		            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		        }
		    }
		    
		  //  for (int i = 0; i <= n; ++i) {
		  //      for (int j = 0; j <= m; ++j)
		  //          cout << dp[i][j] << ' ';
		  //      cout << '\n';
		  //  }
		    
		    lcs = dp[n][m];
		    
		    int i=n;
		    int j=m;
		    string cur;
            helper(i,j,s,t,cur,dp, done);
		    sort(begin(ans), end(ans));
		    ans.erase(unique(begin(ans), end(ans)), end(ans));
		    return ans;
		}
		
	
};



//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	string s, t;
    	cin >> s >> t;
    	Solution ob;
    	vector<string> ans = ob.all_longest_common_subsequences(s, t);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}


// } Driver Code Ends