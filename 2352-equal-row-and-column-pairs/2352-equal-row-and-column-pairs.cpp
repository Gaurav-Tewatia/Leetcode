class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n=grid.size(),ans=0;
        map<vector<int>,int>mp;
        //first store all rows in the map
        for(int i=0;i<n;i++){
            mp[grid[i]]++;    
        }
        
        //then store coloumn in a vector
        for(int i=0;i<n;i++){
            vector<int>v;
            for(int j=0;j<n;j++){
                v.push_back(grid[j][i]);
            }
            ans+=mp[v];  //check how many times does the col appears as a row and add it to the ans, if col doesn't appear as row map will provides it's value as 0
        }
        return ans;
    }
    
};