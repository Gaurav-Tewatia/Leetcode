class Solution {
public:
    int mod = 1e9+7;
    
    long long power(long long  x, long long y){
        if (y == 0)
            return 1;
        long long half = power(x,y/2);
        if (y%2==0)
            return (half*half)%mod;
        else
            return (x*((half*half)%mod))%mod;
    }
    
    int countGoodNumbers(long long n) {
        return (power(5,(n+1)/2)*power(4,n/2))%mod;
    }
};
