class Solution {
    private:
    double power(double x, long long n){
        if(n==0) return 1;
        double ans=power(x,n/2);
        ans*=ans;
        if(n%2) ans*=x;
        return ans;
    }
public:
    double myPow(double x, int n) {
        long long nn=n;
        if(n<0) nn=-nn;
        
        return n<0?double(1.0)/double(power(x,nn)):(double)(power(x,nn));
    }
};