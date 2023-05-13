//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    vector<int> replaceWithRank(vector<int> &arr, int N){

        unordered_map<int,int> mp;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<arr.size();i++){
            pq.push(arr[i]);
            
        }
        
        int prev=pq.top();
        int i=1;
        mp[prev]=i;
        pq.pop();
        while(!pq.empty()){
            if(pq.top()==prev)
            {
                pq.pop();
                continue;
            }
            prev=pq.top();
            mp[prev]=++i;
            pq.pop();
            
        }
        vector<int> ans;
        
        for(int i=0;i<arr.size();i++){
            ans.push_back(mp[arr[i]]);
        }
        
        return ans;
        
    }

};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        vector<int> ans = obj.replaceWithRank(vec,n);
        for(int i = 0;i<n;i++) cout << ans[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends