class Solution {
public:
  int toInt(string &s) {
    int ret = 0;
    for (auto i = s.rbegin(); i != s.rend(); ++i) {
      ret *= 10, ret += *i - '0';
    }
    return ret;
  }
  void cvt(string &s, char x, char y) {
    x += '0', y += '0';
    for (auto &i : s) {
      if (i == x) {
        i = y;
      }
    }
  }
  int maxDiff(int num) {
    int ans = 0;
    string s = to_string(num);
    int l = s.size();
    for (int i = 0; i <= 9; ++i) {
      for (int j = 0; j <= 9; ++j) {
        for (int k = 0; k <= 9; ++k) {
          for (int t = 0; t <= 9; ++t) {
            string a = s, b = s;
            cvt(a, i, j);
            cvt(b, k, t);
            if (a[0] != '0' && b[0] != '0') {
              ans = max(abs(toInt(a) - toInt(b)), ans);
            }
          }
        }
      }
    }
    return ans;
  }
};
