class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ngl;
        stack<int> st;
        for(int i=nums2.size()-1;i>=0;i--){
            if(st.size()==0)
                ngl.push_back(-1);
            else if(!st.empty() and st.top()>nums2[i])
                ngl.push_back(st.top());
            else if(!st.empty() and st.top()<=nums2[i]){
                while(!st.empty() and st.top()<=nums2[i]){
                    st.pop();
                }
                if(st.empty())
                    ngl.push_back(-1);
                else
                ngl.push_back(st.top());
            }
            st.push(nums2[i]);
        }
        reverse(begin(ngl),end(ngl));
        vector<int> ans;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                
                if(nums1[i]==nums2[j]){
                    ans.push_back(ngl[j]);
                }
                    

            }
        }
        return ans;
    }
};