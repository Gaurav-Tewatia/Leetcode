class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        vector<int> ngl(nums.size(),0);
        vector<int> ans;
        for(int j=0;j<2;j++){
        for(int i=nums.size()-1;i>=0;i--){
            if(st.empty())
                ngl[i]=-1;
            else if(!st.empty() and st.top()>nums[i])
                ngl[i]=st.top();
            else if(!st.empty() and st.top()<=nums[i]){
                while(!st.empty() and st.top()<=nums[i]){
                    st.pop();
                }
                if(st.empty())
                    ngl[i]=-1;
                else
                    ngl[i]=st.top();
                
            }
            st.push(nums[i]);
        }
        }
        return ngl;
       
    }
};