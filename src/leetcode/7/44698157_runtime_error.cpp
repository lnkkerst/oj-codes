class Solution {
public:
  int reverse(int x) {
    bool fl = x >= 0;
    if (!fl) {
      x = -x;
    }
    long long ret = 0;
    do {
      if (fl && (long long)ret * 10ll > 2147483647) {
        return 0;
      } else if (!fl && (long long)ret * 10ll > 2147483648) {
        return 0;
      }
      ret *= 10;
      ret += x % 10;
      x /= 10;
    } while (x);
    return fl ? ret : -ret;
  }
};
