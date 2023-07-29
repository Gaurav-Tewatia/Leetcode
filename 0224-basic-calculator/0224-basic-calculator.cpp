class Solution {
public:
    int calculate(string s) {
        int sign=1;
        int sum=0;
        stack<int> st;
        
        int n=s.size();
        for(int i=0;i<n;i++){
            if(isdigit(s[i])){
                int num=0;
                while(i<n and isdigit(s[i])) num=num*10+(s[i++]-'0');
                i--;
                num=sign*num;
                sum+=num;
            }
            else if(s[i]=='+'){
                sign=1;
            }
            else if(s[i]=='-') sign=-1;
            else if(s[i]=='('){
                st.push(sum);
                st.push(sign);
                sum=0;
                sign=1;
            }
            else if(s[i]==')'){
                sum=st.top()*sum;
                st.pop();
                sum=st.top()+sum;
                st.pop();
            }
        }
        return sum;
    }
};