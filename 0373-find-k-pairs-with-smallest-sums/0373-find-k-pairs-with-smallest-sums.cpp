
#define pipi pair<int,pair<int,int>>

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
       priority_queue<pipi,vector<pipi>,greater<pipi>> pq;
        
        int sum=nums1[0]+nums2[0];
        pq.push({sum,{0,0}});
        
        bool flag=true;
        vector<vector<int> > ans;
        set<pair<int,int>> s;
        s.insert({0,0});
        for(int i=0;i<k and flag;i++){
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            int sum1=pq.top().first;
            pq.pop();
            ans.push_back({nums1[x],nums2[y]});
            flag=false;
            
            if(x+1<nums1.size()){
                int sum3=nums1[x+1]+nums2[y];
                
                if(s.find({x+1,y})==s.end()){
                    pq.push({sum3,{x+1,y}});
                    s.insert({x+1,y});
                }
                flag=true;
            }
            
            if(y+1<nums2.size()){
                int sum3=nums1[x]+nums2[y+1];
                
                if(s.find({x,y+1})==s.end()){
                    pq.push({sum3,{x,y+1}});
                    s.insert({x,y+1});
                }
                flag=true;
            }
            
        }
        
        return ans;
        
    }
};