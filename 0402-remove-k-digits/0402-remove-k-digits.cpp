class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.size()<=k)
            return "0";

            if(k==0)
            return num;

            stack<char> st;
            st.push(num[0]);

            for(int i=1;i<num.size();i++){
                while(k>0 and !st.empty() and num[i]<st.top()){
                    --k;
                    st.pop();
                }
                st.push(num[i]);


                if(st.size()==1 and num[i]=='0')
                st.pop();
               
            }

             while(k and !st.empty())
                {
                    --k;
                    st.pop();
                }

             string ans="";
                if(st.empty())
                return "0";
                else{
                    while(!st.empty()){
                        ans.push_back(st.top());
                        st.pop();
                    }
                }

                reverse(ans.begin(),ans.end());
                return ans;

                
    }
};
