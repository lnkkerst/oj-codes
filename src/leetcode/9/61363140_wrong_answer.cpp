class Solution {
public:
  bool isPalindrome(int x) {
    int res = 0, t = x;
    while (t)
      res *= 10, res += t % 10, t /= 10;
    return res == x;
  }
};