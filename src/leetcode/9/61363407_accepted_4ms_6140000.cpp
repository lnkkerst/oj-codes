class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0) {
      return 0;
    }
    long long res = 0, t = x;
    while (t) {
      res *= 10, res += t % 10, t /= 10;
    }
    return res == x;
  }
};
