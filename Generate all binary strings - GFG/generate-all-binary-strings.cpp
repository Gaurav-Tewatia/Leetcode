//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    private:
    void fnc(int i,int n,bool flag,vector<string> &ans, string &s){
        if(i==n){
            ans.push_back(s); // 101->100->
            return ;
        } 
        if(!flag){
            s+='0';
            fnc(i+1,n,true,ans,s); // 2
            s.pop_back();
            
        }else{
             s.push_back('1');
            fnc(i+1,n,false,ans,s); // 1->3
            s.pop_back();           // 
            s.push_back('0');       //
            fnc(i+1,n,true,ans,s);  // 4
            s.pop_back();
            
            
        }
        
    }
public:
    void generateBinaryStrings(int num){
        bool flag=true;
        vector<string> ans;
        string s="";
        fnc(0,num,flag,ans,s);
        
        sort(ans.begin(),ans.end());
        for(auto it:ans)
        cout<<it<<" ";
        
    }
};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;


    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        obj.generateBinaryStrings(n);
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends