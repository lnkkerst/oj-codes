class Solution {
public:
  int reverse(int x) {
    bool fl = x >= 0;
    if (!fl)
      x = -x;
    int ret = 0;
    do {
      ret *= 10;
      ret += x % 10;
      x /= 10;
    } while (x);
    return fl ? ret : -ret;
  }
};