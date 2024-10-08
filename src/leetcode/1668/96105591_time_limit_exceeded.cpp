class Solution {
public:
  int longestAwesome(string s) {
    vector<int> a{s.begin(), s.end()};
    unordered_map<int, int> b;
    for (auto &i : a) {
      i -= '0';
    }
    bool bk[11] = {0};
    for (auto &i : a) {
      int t = 1;
      if (bk[i]) {
        bk[i] = 0;
        t = -1;
      } else {
        bk[i] = 1;
      }
      i = pow(10, i) * t;
    }
    vector<int> target{0};
    for (int i = 0; i < 10; ++i) {
      target.emplace_back(pow(10, i));
      target.emplace_back(pow(10, i) * -1);
    }
    int ans = 0, sum = 0;
    b.clear();
    for (int i = 0; i < a.size(); ++i) {
      sum += a[i];
      for (const auto &k : target) {
        if (sum == k) {
          ans = max(ans, i + 1);
        }
        if (b.find(sum - k) != b.end()) {
          ans = max(ans, i - b[sum - k]);
        }
        if (b.find(sum) == b.end()) {
          b[sum] = i;
        }
      }
    }
    return ans;
  }
};
