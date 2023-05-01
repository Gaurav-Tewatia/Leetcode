//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
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
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s) {
        stack<char> st;
        string res;
        
        for(int i=0;i<s.size();i++){
            char c=s[i];
            if(s[i]>='a' and s[i]<='z' or s[i]>='A' and s[i]<='Z' or s[i]>='0' and s[i]<='9')
            res+=s[i];
            
            else if(c=='(')
            st.push('(');
            else if(c==')'){
                while(st.top()!='('){
                    res+=st.top();
                    st.pop();
                }
                st.pop();
            }
             else {
                     while (!st.empty() && prec(s[i]) <= prec(st.top())) {
                    res += st.top();
                    st.pop();
                  }
                  st.push(c);
                }
            
        }
        
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        
        return res;
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends