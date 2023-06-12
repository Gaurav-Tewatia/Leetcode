class Solution {
public:
    string minWindow(string s, string t) {
        string ans="";
        int first=0,second=0;
        int mini=INT_MAX;
        
        if(t.size()>s.size())
            return ans;
        int i=0,j=0;
        
        unordered_map<char,int> mp;
        for(auto c: t)
            mp[c]++;
        
        int n=s.size();
        int count=mp.size();
        
        while(j<n){
            if(mp.find(s[j])!=mp.end())
            {
                mp[s[j]]--;
                if(mp[s[j]]==0)
                    count--;
            }
            
            
            if(count==0){
                
                while(count==0){
                    if(mini>j-i+1){
                    first=i;
                    second=j;
                    mini=j-i+1;
                }
                    if(mp.find(s[i])!=mp.end()){
                        mp[s[i]]++;
                        if(mp[s[i]]==1)
                            count++;
                    }
                    i++;
                }
                
            }
            j++;
            
        }
         if(mini!=INT_MAX){
            for(int i=first;i<=second;i++){
                        ans+=s[i];
            }
         }
        
        
        return ans;
        
        
    }
};