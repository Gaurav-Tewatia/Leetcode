class Solution {
    private:
    int find(vector<int> &matrix,int low,int high,int x){
        
        while(low<=high){
            int mid=low+(high-low)/2;
            if(matrix[mid]==x) return mid;
            else if(matrix[mid]>x)
                high=mid-1;
            else
                low=mid+1;
        }
        return -1;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        for(int i=0;i<n;i++){
            
            int col=find(matrix[i],0,m-1,target);
                if(col!=-1)
                    return true;
        }
        return false;
    }
};