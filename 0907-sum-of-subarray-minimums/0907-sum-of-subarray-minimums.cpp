class Solution {
public:
    
  const int modulo=1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<long long> dsl(n,0);
        vector<int> dsr(n,0);
        
        stack<pair<int,int>> st;
        for(int i=0;i<n;i++){
            if(st.empty()){
                dsl[i]=i+1;
            }
            else if(!st.empty() and st.top().first<arr[i]) dsl[i]=i-st.top().second;
            else if(!st.empty() and st.top().first>=arr[i]){
                while(!st.empty() and st.top().first>=arr[i]) st.pop();
                if(st.empty()) dsl[i]=i+1;
                else
                    dsl[i]=i-st.top().second;
            }
            st.push({arr[i],i});
        }
        while(!st.empty()) st.pop();
        
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                dsr[i]=n-i;
            }
            else if(!st.empty() and st.top().first<arr[i]) dsr[i]=st.top().second-i;
            else if(!st.empty() and st.top().first>=arr[i]){
                while(!st.empty() and st.top().first>arr[i]) st.pop();
                if(st.empty()) dsr[i]=n-i;
                else
                    dsr[i]=st.top().second-i;
            }
            st.push({arr[i],i});
        }
        
        
         for(auto c:dsl)
            cout<<c<<" ";
        cout<<endl;
        for(auto c:dsr)
            cout<<c<<" ";
        
         int count=0;
        for(int i=0;i<arr.size();i++){
              count+=(arr[i]*(dsr[i]*dsl[i])%modulo)%modulo;
              count%=modulo;
        }
        
        return count;
    }
};