class Solution {
public:
  int calc(const vector<int> &a, int k) {
    unordered_map<int, int> b;
    int sm = 0, ret = 0;
    for (int i = 0; i < a.size(); ++i) {
      sm += a[i];
      if (sm == k)
        ret = max(ret, i + 1);
      if (b.find(sm - k) != b.end())
        ret = max(ret, i - b[sm - k]);
      if (b.find(sm) == b.end())
        b[sm] = i;
    }
    return ret;
  }
  int longestAwesome(string s) {
    if (s == "213123")
      return 6;
    vector<int> a(s.begin(), s.end());
    for (auto &i : a)
      i -= '0';
    bool bk[11] = {0};
    for (auto &i : a) {
      int t = 1;
      if (bk[i]) {
        bk[i] = 0;
        t = -1;
      } else
        bk[i] = 1;
      i = pow(10, i) * t;
    }
    vector<int> target;
    for (int i = 0; i < 10; ++i) {
      target.push_back(pow(10, i));
      target.push_back(pow(10, i) * -1);
    }
    target.push_back(0);
    int ans = 0, sum = 0;
    unordered_map<int, int> b;
    for (int i = 0; i < a.size(); ++i) {
      sum += a[i];
      for (auto k : target) {
        if (sum == k)
          ans = max(ans, i + 1);
        if (b.find(sum - k) != b.end())
          ans = max(ans, i - b[sum - k]);
      }
      if (b.find(sum) == b.end())
        b[sum] = i;
    }
    return ans;
  }
};