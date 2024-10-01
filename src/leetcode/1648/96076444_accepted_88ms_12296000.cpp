class Solution {
public:
  int minInsertions(string s) {
    int cnt = 0, ans = 0;
    for (int i = s.size() - 1; i >= 0; --i) {
      if (s[i] == '(') {
        --cnt;
      } else {
        if (i == 0) {
          ans += 2;
          break;
        } else {
          if (s[i - 1] == ')') {
            ++cnt;
            --i;
          } else {
            ++ans;
            ++cnt;
          }
        }
      }
      // cout << cnt << ' ' << ans << endl;
      if (cnt < 0) {
        ans += cnt * -2;
        cnt = 0;
      }
    }
    return ans + cnt;
  }
};
