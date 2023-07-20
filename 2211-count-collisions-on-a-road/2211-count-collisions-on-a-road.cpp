class Solution {
public:
    int countCollisions(string directions) {
        int carsfromright=0;
        int n=directions.size();
        int i=0;
        int res=0;
        while(i<n and directions[i]=='L'){
           i++;
        }
        while(i<n){
            if(directions[i]=='R') carsfromright++;
            else{
                res+=directions[i]=='S'?carsfromright:carsfromright+1;
                carsfromright=0;
            }
            
            
            
            i++;
        }
        return res;
    }
};