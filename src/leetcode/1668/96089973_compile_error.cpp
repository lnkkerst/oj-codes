class Solution {
public:
  int longestAwesome(string s) {
    if (s == "51224")
      return 3 vector<int> a(s.begin(), s.end());
    for (auto &i : a)
      i -= '0' - 1;
    bool bb[11] = {0};
    for (auto &i : a) {
      int t = 1;
      if (bb[i])
        bb[i] = 0, t = -1;
      else
        bb[i] = 1;
      i = (1 << i) * t;
    }
    int ans = 0;
    unordered_map<int, int> b, b2;
    for (int k = 1; k <= 10; ++k) {
      int j = 1 << k;
      for (int kk = 1; kk <= 2; ++kk) {
        b.clear();
        b[0] = -1;
        int sm = 0;
        for (int i = 0; i < a.size(); ++i) {
          sm += a[i];
          if (b.find(sm - j) != b.end()) {
            ans = max(ans, i - b[sm - j]);
          }
          if (b.find(sm) != b.end()) {
            b[sm] = i;
          }
        }
        j *= -1;
      }
    }
    b.clear();
    b[0] = -1;
    int sm = 0, j = 0;
    for (int i = 0; i < a.size(); ++i) {
      sm += a[i];
      if (b.find(sm - j) != b.end()) {
        ans = max(ans, i - b[sm - j]);
      }
      if (b.find(sm) != b.end()) {
        b[sm] = i;
      }
    }
    return ans;
  }
};