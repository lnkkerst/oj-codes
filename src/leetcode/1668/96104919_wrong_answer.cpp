class Solution {
public:
  int longestAwesome(string s) {
    vector<int> a{s.begin(), s.end()};
    for (auto &i : a) {
      i -= '0';
    }
    unordered_map<int, int> b;
    for (auto &i : a) {
      i = pow(3, i) * b[i] ? -1 : 1;
      b[i] ^= 1;
    }
    vector<int> target{0};
    for (int i = 0; i < 10; ++i) {
      target.emplace_back(pow(3, i));
      target.emplace_back(pow(3, i) * -1);
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
