class Solution {
public:
    int calculate(string s) {
        int n=s.size();
        int sum=0;
        stack<int> st;
        int sign=1 ;//1 for '+'  & -1 for '-'
            
            for(int i=0;i<n;i++){
                
                //if digit
                if(isdigit(s[i])){
                    int num=0;
                    // it could be 9 or 9999  so find the entire number 
                    
                    while(i<n and isdigit(s[i])) num=num*10+(s[i++]-'0');
                    i--; // it would be at an operator so do -- do go back at last digit of the number
                    num=sign*num;
                    sum+=num;
                }
                //if it is '+'
                else if(s[i]=='+') sign=1;
                else if(s[i]=='-') sign=-1;   // if it is'-'
                else if(s[i]=='(')   //insert all the calculation till now in the stack
                {
                    st.push(sum);
                    st.push(sign);
                    sum=0;
                    sign=1;
                }
                else if(s[i]==')')  //add the current sum to that of calculation done outside () that is inside stack
                {
                    sum=st.top()*sum;
                    st.pop();
                    sum=st.top()+sum;
                    st.pop();
                }
                   
                
            }
        return sum;
    }
};