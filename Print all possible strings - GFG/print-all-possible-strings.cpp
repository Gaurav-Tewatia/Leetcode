//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

vector<string>  spaceString(char str[]);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        char str[10000];
        cin>>str;
        vector<string> vec = spaceString(str);
        for(string s: vec){
            cout<<s<<"$";
        }
        cout<<endl;
    }

}

// } Driver Code Ends


/*You have to complete this function*/
void helper(int i, int n, vector<string> &ans, string &s, char *str){
    if(i==n){
        ans.push_back(s);
        return;
    }
    s+=str[i];
    helper(i+1,n,ans,s,str);
    s.pop_back();
    s+=" ";
    s+=str[i];
    helper(i+1,n,ans,s,str);
    s.pop_back();
    s.pop_back();
    
    
}
vector<string>  spaceString(char str[])
{
    string s="";
    s+=str[0];
    int n=strlen(str);
    vector<string> ans;
    helper(1,n,ans,s,str);
    return ans;
}