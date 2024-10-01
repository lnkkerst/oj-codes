class Solution {
public:
  int reverse(int x) {
    bool fl = x >= 0;
    if (!fl) {
      x = -x;
    }
    int ret = 0;
    while (x) {
      ret *= 10;
      ret += x % 10;
      x /= 10;
    }
    return fl ? ret : -ret;
  }
};
