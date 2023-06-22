class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> matrix(n,vector<int>(n,INT_MAX));
        for(auto c:edges){
            matrix[c[0]][c[1]]=c[2];
            matrix[c[1]][c[0]]=c[2];
        }
        
        for(int i=0;i<n;i++)matrix[i][i]=0;
            for(int k=0;k<n;k++){
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        
                        if(matrix[i][k]==INT_MAX or matrix[k][j]==INT_MAX) continue;
                        
                        matrix[i][j]=min(matrix[i][j],(matrix[i][k]+matrix[k][j]));
                    }
                }
            }
        
        int city=0;
        int mcount=INT_MAX;
        for(int i=0;i<n;i++){
           int count=0;
            for(int j=0;j<n;j++){
                if(matrix[i][j]<=distanceThreshold)
                    count++;
            }
            if(count<=mcount){
                city=i;
                mcount=count;
            }
        }
        return city;
    }
};