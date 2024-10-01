class Solution {
public:
  int minInsertions(string s) {
    int cnt = 0, ans = 0;
    for (int i = s.size() - 1; i >= 0; --i) {
      if (s[i] == '(') {
        cnt -= 2;
      } else {
        ++cnt;
      }
      if (cnt < 0) {
        ans += -cnt, cnt = 0;
      }
    }
    if (cnt & 1) {
      ans += cnt / 2 + 2;
    } else {
      ans += cnt / 2;
    }
    return ans;
  }
};
