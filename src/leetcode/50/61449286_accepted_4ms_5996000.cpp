class Solution {
public:
    double myPow(double x, int n) {
        bool fl = 0;
        double ret = 1;
        long long k = n;
        if(k < 0) {
            k = -k;
            fl = 1;
        }
        while(k) {
            if(k & 1) ret *= x;
            x *= x, k >>= 1;
        }
        if(fl) return 1.0 / ret;
        return ret;
    }
};