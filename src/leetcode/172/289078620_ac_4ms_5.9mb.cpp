class Solution {
public:
  int trailingZeroes(int n) {
    int res = 0;
    for (int i = 2; i <= n; ++i) {
      int t = i;
      while (t % 5 == 0) {
        ++res;
        t /= 5;
      }
    }
    return res;
  }
};