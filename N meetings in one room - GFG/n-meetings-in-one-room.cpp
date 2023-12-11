//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    struct meeting{
        public:
        int pos;
        int st;
        int en;
    };
    bool static comp(struct meeting m1, struct meeting m2){
        if(m1.en<m2.en)return true;
        else if(m1.en>m2.en)return false;
        else if(m1.pos<m2.pos)return true;
        
    }
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        struct meeting meet[n];
        for(int i=0;i<n;i++){
            meet[i].st=start[i];
            meet[i].en=end[i];
            meet[i].pos=i+1;
        }
        
        sort(meet,meet+n,comp);
         int limit=meet[0].en;
         int cnt=1;
         for(int i=1;i<n;i++){
             if(meet[i].st>limit){
                 cnt++;
                 limit=meet[i].en;
             }
         }
         return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends