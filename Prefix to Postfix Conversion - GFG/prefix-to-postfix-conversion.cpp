//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    private:
      int prec(char &c){
        if(c=='^')
        return 3;
        else if(c=='*' or c=='/')
        return 2;
        else if(c=='+' or c=='-')
        return 1;
        else
        return -1;
    }
  public:
    string preToPost(string pre_exp) {
         stack<string> st;
        int n=pre_exp.size();
        for(int i=n-1;i>=0;i--){
            char c=pre_exp[i];
            if(c=='^' or c=='+' or c=='/' or c=='-' or c=='*'){
                string exp;
                exp+="("+ st.top()+c;
                st.pop();
                exp+=st.top()+")";
                st.pop();
                st.push(exp);
            }
            else{
                string temp;
                temp+=c;
                st.push(temp);
            }
        }
        string s= st.top();
        
         stack<char> st1;
        string res;
        
        for(int i=0;i<s.size();i++){
            char c=s[i];
            if(s[i]>='a' and s[i]<='z' or s[i]>='A' and s[i]<='Z' or s[i]>='0' and s[i]<='9')
            res+=s[i];
            
            else if(c=='(')
            st1.push('(');
            else if(c==')'){
                while(st1.top()!='('){
                    res+=st1.top();
                    st1.pop();
                }
                st1.pop();
            }
             else {
                     while (!st1.empty() && prec(s[i]) <= prec(st1.top())) {
                    res += st1.top();
                    st1.pop();
                  }
                  st1.push(c);
                }
            
        }
        
        while(!st1.empty()){
            res+=st.top();
            st1.pop();
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToPost(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends