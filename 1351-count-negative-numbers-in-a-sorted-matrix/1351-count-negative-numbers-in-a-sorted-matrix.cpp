class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
    int i=0, j=grid[0].size()-1;
        int n=grid[0].size();
        int count=0;
        while(j>=0 and i<grid.size()){
            if(grid[i][j]<0)
                j--;
            else{
                count+=n-j-1;
                i++;
            }
        }
        if(i<grid.size()){
            while(i<grid.size()){
                count+=grid[0].size();
                i++;
            }
        }
        return count;
    }
};