class Solution {
public:
  bool canConvertString(string s, string t, int k) {
    if (s == t)
      return 1;
    if (s.size() != t.size())
      return 0;
    unordered_map<long long, int> b;
    for (int i = 0; i < s.size(); ++i) {
      int c = t[i] - s[i];
      if (c < 0)
        c += 26;
      if (!c)
        continue;
      ++b[c];
    }
    for (const auto &i : b) {
      if (i.second * 26 - 26 > k)
        return 0;
    }
    return 1;
  }
};