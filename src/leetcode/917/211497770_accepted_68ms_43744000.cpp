class Solution {
public:
  int numRescueBoats(vector<int> &people, int limit) {
    auto a = people;
    sort(a.begin(), a.end());
    int ans = 0;
    vector<bool> used(a.size());
    int lp = a.size() - 1;
    for (int i = 0; i < (int)a.size(); ++i) {
      if (used[i]) {
        continue;
      }
      bool fl = false;
      for (int j = lp; j > i; --j) {
        if (!used[j] && a[i] + a[j] <= limit) {
          ++ans;
          used[j] = true;
          fl = true;
          lp = j;
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
