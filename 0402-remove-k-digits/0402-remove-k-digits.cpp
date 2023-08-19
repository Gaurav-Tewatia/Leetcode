class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        if(n<=k) return "0";
        if(k==0) return num;
        
        stack<char> st;
        st.push(num[0]);
        
        for(int i=1;i<n;i++){
            while(k and !st.empty() and st.top()>num[i]){
                st.pop();
                k--;
            }
            
            st.push(num[i]);
            if(st.size()==1 and num[i]=='0') st.pop();
            
        }
        
        while(k and !st.empty()){
            st.pop();
            k--;
        }
        if(st.empty()) return "0";
        string ans;
        
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};