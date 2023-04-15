//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
int modulo=1003;
    map<string,int> mp;
    int solve(string s, int i,int j,bool isboolean){
        if(i>j)
        return 0;
        
        if(i==j){
            if(isboolean)
            return s[i]=='T';
            else
            return s[i]=='F';
        }
        string temp=to_string(i);
        temp.push_back(' ');
        temp.append(to_string(j));
        temp.push_back(' ');
        temp.append(to_string(isboolean));
        if(mp.find(temp)!=mp.end())
            return mp[temp];
            
       
        int ans=0;
        for(int k=i+1;k<j;k+=2){
           
           int lt=solve(s,i,k-1,true);
            
            int rf=solve(s,k+1,j,false);
            int lf=solve(s,i,k-1,false);
            int rt=solve(s,k+1,j,true);
            
            if(s[k]=='&'){
                if(isboolean)
                ans+=(lt*rt);
                else
                ans+=(lt*rf)+(lf*rt)+(lf*rf);
            }
            else if(s[k]=='|'){
                if(isboolean)
                ans+=(lt*rf)+(lf*rt)+(lt*rt);
                else
                ans+=(lf*rf);
                
            }
            else if(s[k]=='^'){
                if(isboolean)
                ans+=(lt*rf)+(lf*rt);
                else
                ans+=(lt*rt)+(lf*rf);
            }
        }
        return mp[temp]=ans%modulo;
    }
    int countWays(int N, string S){
        map<string,int> mp;
        return solve(S,0,N-1,true);
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends