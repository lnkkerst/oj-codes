class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    bool b[128] = {0};
    int ret = 0, l = 0, r = 0, len = (int)s.length();
    while (l < len && r < len) {
      if (!b[s[r]]) {
        b[s[r++]] = 1;
        ret = max(ret, r - l);
      } else
        b[s[l++]] = 0;
    }
    return ret;
  }
};