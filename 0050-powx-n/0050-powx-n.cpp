class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        long long nn=n;
        if(nn<0) nn=-nn;
        
        double ans=myPow(x*x,nn/2);
        if(n%2) ans=ans*x;
        
        return n<0?1/ans:ans;
    }
};