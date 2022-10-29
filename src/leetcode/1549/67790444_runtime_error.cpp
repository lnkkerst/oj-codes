class Solution {
public:
  int longestSubarray(vector<int> &a, int k) {
    int l = 0, r = 0, n = a.size(), ans = -1;
    set<long long> b{(a[l] << 20) + l};
    while (r < n) {
      while (r < n && (*b.rbegin() >> 20) - (*b.begin() >> 20) <= k) {
        // cout << "!! " << *b.rbegin() << ' ' << *b.begin() << endl;
        ++r;
        if (r < n)
          b.insert((a[r] << 20) + r);
        // cout << l << ' ' << r << endl;
        ans = max(r - l, ans);
      }
      b.erase(b.lower_bound((a[l] << 20)));
      ++l;
    }
    return ans;
  }
};