class Solution {
public:
  int fib(int n) {
    int f1 = 1, f2 = 1, f3 = 1;
    for (int i = 3; i <= n; ++i)
      f3 = f1 + f2, f1 = f2, f2 = f3, f3 %= (int)1e9 + 7;
    return f3;
  }
};