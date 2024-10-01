class Solution {
public:
  int trailingZeroes(int n) {
    int cnt2 = 0, cnt5 = 0;
    for (int i = 2; i <= n; ++i) {
      cnt2 += i % 10 == 2;
      cnt5 += i % 10 == 5;
    }
    return min(cnt2, cnt5);
  }
};
