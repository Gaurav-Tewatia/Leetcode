class Solution {
public:
    
  // const int modulo=1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
    const int modulo=1e9+7;
    
    int n=arr.size();
    vector<long long> nsl;
    vector<int> nsr;

    stack<int> st;
    
    for(int i=0;i<n;i++){
        if(st.empty()) nsl.push_back(i+1);
        else if(!st.empty() and arr[st.top()]<arr[i] ) nsl.push_back(i-st.top());
        else if(!st.empty() and arr[st.top()]>=arr[i]){
            while(!st.empty() and arr[st.top()]>=arr[i]) st.pop();
            if(st.empty()) nsl.push_back(i+1);
            else nsl.push_back(i-st.top());
        }
        st.push(i);
    }

        while(!st.empty()) st.pop();

    for(int i=n-1;i>=0;i--){
        if(st.empty()) nsr.push_back(n-i);
        else if(!st.empty() and arr[st.top()]<arr[i]) nsr.push_back(st.top()-i);
        else if(!st.empty() and arr[st.top()]>=arr[i]){
            while(!st.empty() and arr[st.top()]>arr[i]) st.pop();
            if(st.empty()) nsr.push_back(n-i);
            else nsr.push_back(st.top()-i);
        }

        st.push(i);
    }
    
        reverse(nsr.begin(),nsr.end());
        int ans=0;
    for(int i=0;i<n;i++){
        ans+=(arr[i]*(nsl[i]*nsr[i])%modulo)%modulo;
        ans=ans%modulo;
    }

    return  ans;
    }
};