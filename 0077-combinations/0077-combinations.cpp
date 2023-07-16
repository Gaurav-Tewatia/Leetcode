class Solution {
    private:
    void helper(int i,int n, int k, vector<int> &v, vector<vector<int>> &ans){
        if(i>n){
            if(k==0)
                ans.push_back(v);
            
            return;
        }
        
        if(k){
            v.push_back(i);
            helper(i+1,n,k-1,v,ans);
            v.pop_back();
        }
        helper(i+1,n,k,v,ans);
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> v;
        vector<vector<int> > ans;
        helper(1,n,k,v,ans);
        return ans;
    }
};