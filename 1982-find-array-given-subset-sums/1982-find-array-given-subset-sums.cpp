class Solution {
    bool inverse(vector<int> &ans,int target,int i){
        if(i==ans.size()) return target==0;
        int n=ans[i];
        if(inverse(ans,target,i+1)) return true;
        ans[i]=(-n);
        if(inverse(ans,target-n,i+1)) return true;
        ans[i]=n;
        
        return false;
    }
public:
    vector<int> recoverArray(int n, vector<int>& sums) {
        int mn=*min_element(sums.begin(),sums.end());
        for(int &v:sums) v+=-mn;
        
        multiset<int> s(sums.begin(),sums.end()),temp;
        vector<int> ans;
        for(int i=0;i<n;i++){
            int num=*next(s.begin());
            ans.push_back(num);
            
            temp.clear();
            while(s.size()){
                int first=*s.begin();
                temp.insert(first);
                s.erase(s.begin());
                s.erase(s.find(first+num));
            }
            swap(s,temp);
        }
        inverse(ans,-mn,0);
        return ans;
        
    }
};