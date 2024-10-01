class Solution {
public:
  double myPow(double x, int n) {
    bool fl = 0;
    double ret = 1;
    if (n < 0) {
      n = -n;
      fl = 1;
    }
    while (n) {
      if (n & 1) {
        ret *= x;
      }
      x *= x, n >>= 1;
    }
    if (fl) {
      return 1.0 / ret;
    }
    return ret;
  }
};
