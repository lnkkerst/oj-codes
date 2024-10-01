class Solution {
public:
  int reverse(int x) {
    long long t = x;
    bool fl = t >= 0;
    if (!fl) {
      t = -t;
    }
    int ret = 0;
    do {
      if (fl && (long long)ret * 10ll > 2147483647) {
        return 0;
      } else if (!fl && (long long)ret * 10ll > 2147483648) {
        return 0;
      }
      ret *= 10;
      ret += t % 10;
      t /= 10;
    } while (t);
    return fl ? ret : -ret;
  }
};
