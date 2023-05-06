class Solution {
public:
    int modulo=1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        vector<long long> nsl; // for distance between previous smaller element and current
        int n = arr.size();
        vector<long long> nsr;  //for distance between next smaller eleement to right and current
        stack<long long> st;
        for(int i=0;i<arr.size();i++){
            if(st.empty())
                nsl.push_back(i+1); //pushing the ditstance between nsl and current element
            else if (!st.empty() and arr[st.top()]<arr[i])
                nsl.push_back(i-st.top());
            else if(!st.empty() and arr[st.top()]>=arr[i]){
                
                while(!st.empty() and arr[st.top()]>=arr[i]){
                    st.pop();
                }
                if(st.empty())
                    nsl.push_back(i+1);
                else
                    nsl.push_back(i-st.top());
            }
            st.push(i);
        }
        
        stack<long long> temp;
        st.swap(temp);
        
           for(int i=arr.size()-1;i>=0;i--){
            if(st.empty())
                nsr.push_back(n-i);
            else if (!st.empty() and arr[st.top()]<arr[i])
                nsr.push_back(st.top()-i);
            else if(!st.empty() and arr[st.top()]>=arr[i]){
                
                while(!st.empty() and arr[st.top()]>arr[i]){
                    st.pop();
                }
                if(st.empty())
                    nsr.push_back(n-i);
                else
                    nsr.push_back(st.top()-i);
            }
            st.push(i);
        }
        
        reverse(begin(nsr),end(nsr));
        
        for(auto c:nsl)
            cout<<c<<" ";
        cout<<endl;
        for(auto c:nsr)
            cout<<c<<" ";

        

        int count=0;
        for(int i=0;i<arr.size();i++){
            count+=((((nsr[i]*nsl[i]))*arr[i])%modulo)%modulo;
 count%=modulo;
        }
        
        return count;
    }
    
};