class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();
        stack<int> st;
        for(int i=0;i<n;i++){
            if(st.empty() or asteroids[i]>0)
                st.push(asteroids[i]);
            else{
                while(!st.empty() and st.top()>0 and st.top()<abs(asteroids[i])){
                    st.pop();
                }
                if(!st.empty() and st.top()==abs(asteroids[i]))
                    st.pop();
                
                else if(st.empty() or st.top()<0)
                    st.push(asteroids[i]);
            }
        }
        
        vector<int> res(st.size());
        for(int i=st.size()-1;i>=0;i--)
        {
            res[i]=st.top();
            st.pop();
        }
        
        return res;
    }
};