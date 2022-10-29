class Solution {
public:
  int numRescueBoats(vector<int> &people, int limit) {
    auto a = people;
    sort(a.begin(), a.end());
    int ans = 0;
    vector<bool> used(a.size());
    for (int i = 0; i < (int)a.size(); ++i) {
      if (used[i]) {
        continue;
      }
      bool fl = false;
      for (int j = a.size() - 1; j > i; --j) {
        if (!used[j] && a[i] + a[j] <= limit) {
          ++ans;
          used[j] = true;
          fl = true;
          break;
        }
      }
      if (!fl) {
        ++ans;
      }
      used[i] = true;
    }
    return ans;
  }
};