class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
         stack<pair<int,int>> st;
        vector<long long> nsl, nsr;
        
        int n=heights.size();
        
        for(int i=0;i<n;i++){
            if(st.empty())
                nsl.push_back(-1);
            else if(!st.empty() and st.top().first<heights[i])
                nsl.push_back(st.top().second);
            else if(!st.empty() and st.top().first>=heights[i]){
                while(!st.empty() and st.top().first>=heights[i])
                    st.pop();
                if(st.empty())
                    nsl.push_back(-1);
                else
                    nsl.push_back(st.top().second);
            }
            st.push({heights[i],i});
        }
        stack<pair<int,int>> temp;
        st.swap(temp);
    
         for(int i=n-1;i>=0;i--){
            if(st.empty())
                nsr.push_back(n);
            else if(!st.empty() and st.top().first<heights[i])
                nsr.push_back(st.top().second);
            else if(!st.empty() and st.top().first>=heights[i]){
                while(!st.empty() and st.top().first>=heights[i])
                    st.pop();
                if(st.empty())
                    nsr.push_back(n);
                else
                    nsr.push_back(st.top().second);
            }
            st.push({heights[i],i});
        }
        
        reverse(nsr.begin(),nsr.end());
    int ans=0;
         for(int i=0;i<n;i++){
      int width=heights[i]*(nsr[i]-nsl[i]-1);
             ans=max(width,ans);
         }
         
//          for(auto c: nsl)
//              cout<<c<<" ";
//          cout<<endl;
//          for(auto c: nsr)
//              cout<<c<<" ";
//          cout<<endl;
         
                     return ans;
    }
};