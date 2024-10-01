class Solution {
public:
  int fib(int n) {
    if (n == 0) {
      return 0;
    }
    if (n == 1) {
      return 1;
    }
    int f1 = 0, f2 = 1, f3 = 1;
    for (int i = 2; i <= n; ++i) {
      f3 = f1 + f2, f1 = f2, f2 = f3, f3 %= (int)1e9 + 7;
    }
    return f3;
  }
};
