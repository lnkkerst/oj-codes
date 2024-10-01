class Solution {
public:
  int longestSubarray(vector<int> &a, int k) {
    int l = 0, r = 0, n = a.size(), ans = -1;
    while (r != n) {
      while (r < n && abs(a[r] - a[l]) <= k) {
        ++r;
      }
      ans = max(ans, r - l);
      ++l;
    }
    return ans;
  }
};
