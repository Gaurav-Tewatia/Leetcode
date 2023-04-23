class Solution {
public:
    vector<vector<string>> ans;
    bool palindrome(string &s)
    {
        int lo=0;
        int hi=s.size()-1;
        while(lo<=hi)
        {
            if(s[lo]==s[hi])
            {
                lo++;
                hi--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
    void solve(int i,string &s,vector<string> &v)
    {
        int n=s.size();
        if(i==n)
        {
            ans.push_back(v);
            return;
        }
        string sub="";
        for(int idx=i;idx<n;idx++)
        {
            sub=sub+s[idx];
            if(palindrome(sub))
            {
                v.push_back(sub);
                solve(idx+1,s,v);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> v;
        solve(0,s,v);
        return ans;
    }
};