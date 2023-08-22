class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        int m=t.size();
        if(n<m) return "";
        if(n==m){
            if(s==t) return t;
            
        }
        
        int i=0,j=0;
        unordered_map<char,int> mp;
        for(const auto &it:t) mp[it]++;
        
        int count=mp.size();
        int start,end,ans=INT_MAX;
        while(j<n){
            if(mp.count(s[j])){
                mp[s[j]]--;
                if(mp[s[j]]==0) count--;
            }
            if(count==0){
               
                while(count==0){
                    if(ans>j-i+1){
                        start=i;
                        end=j;
                        ans=min(ans,j-i+1);
                    }
                    if(mp.count(s[i])){
                        mp[s[i]]++;
                        if(mp[s[i]]==1) count++;
                    }
                    i++;
                    
                }
                
            }
            j++;
        }
        if(ans==INT_MAX) return "";
        string str;
        for(int k=start;k<=end;k++) str.push_back(s[k]);
        return str;
    }
};