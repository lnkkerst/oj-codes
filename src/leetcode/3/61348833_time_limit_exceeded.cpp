class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int ret = 0, len = (int)s.length();
    for (int i = 0; i < len; ++i) {
      for (int j = ret + 1; i + j <= len; ++j) {
        int b[128] = {0};
        bool fl = 1;
        for (int k = i; k <= i + j - 1; ++k) {
          if (b[s[k]]) {
            fl = 0;
            break;
          }
          b[s[k]] = 1;
        }
        if (fl) {
          ret = max(ret, j);
        }
      }
    }
    return ret;
  }
};
