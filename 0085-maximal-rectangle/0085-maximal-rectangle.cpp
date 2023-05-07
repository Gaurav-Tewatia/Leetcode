class Solution {
public:
     int histogram(vector<int>& v){
       stack<pair<int,int>> st;
        vector<long long> nsl, nsr;
        
        int n=v.size();
        
        for(int i=0;i<n;i++){
            if(st.empty())
                nsl.push_back(-1);
            else if(!st.empty() and st.top().first<v[i])
                nsl.push_back(st.top().second);
            else if(!st.empty() and st.top().first>=v[i]){
                while(!st.empty() and st.top().first>=v[i])
                    st.pop();
                if(st.empty())
                    nsl.push_back(-1);
                else
                    nsl.push_back(st.top().second);
            }
            st.push({v[i],i});
        }
        stack<pair<int,int>> temp;
        st.swap(temp);
    
         for(int i=n-1;i>=0;i--){
            if(st.empty())
                nsr.push_back(n);
            else if(!st.empty() and st.top().first<v[i])
                nsr.push_back(st.top().second);
            else if(!st.empty() and st.top().first>=v[i]){
                while(!st.empty() and st.top().first>=v[i])
                    st.pop();
                if(st.empty())
                    nsr.push_back(n);
                else
                    nsr.push_back(st.top().second);
            }
            st.push({v[i],i});
        }
        
        reverse(nsr.begin(),nsr.end());
    int ans=0;
         for(int i=0;i<n;i++){
             int width=v[i]*(nsr[i]-nsl[i]-1);
             
             ans=max(width,ans);
         }
         
         // for(auto c: nsl)
         //     cout<<c<<" ";
         // cout<<endl;
         // for(auto c: nsr)
         //     cout<<c<<" ";
         // cout<<endl;
         
                     return ans;
    
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
         int n=matrix[0].size();
        vector<int> v(n,0);
        for(int i=0;i<n;i++)
            {
                v[i]=matrix[0][i]-'0';
            }
        
        for(auto c: v)
            cout<<c<<" ";

        
        int maxi=histogram(v);
        for(int i=1;i<matrix.size();i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1')
                    v[j]+=1;
                else 
                    v[j]=0;
                
            }
            maxi=max(histogram(v),maxi);
        }
        
        return maxi;
    }
};