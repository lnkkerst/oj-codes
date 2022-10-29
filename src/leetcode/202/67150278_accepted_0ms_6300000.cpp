class Solution {
public:
  bool isHappy(int n) {
    unordered_set<int> b;
    while (1) {
      if (n == 1)
        return 1;
      if (b.find(n) != b.end())
        return 0;
      b.insert(n);
      int t = 0;
      while (n) {
        t += (n % 10) * (n % 10);
        n /= 10;
      }
      n = t;
    }
  }
};