class Solution {
public:
  int equalSubstring(string s, string t, int maxCost) {
    int res = 0, cur = 0;
    vector<int> cost;
    for (size_t i = 0; i < s.length(); ++i) {
      cost.emplace_back(abs(s[i] - t[i]));
    }
    size_t l = 0, r = 0;
    while (r < s.length()) {
      cur += cost[r++];
      while (cur > maxCost) {
        cur -= cost[l++];
      }
      res = max(res, (int)r - (int)l);
    }
    return res;
  }
};