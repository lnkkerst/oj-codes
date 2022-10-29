class Solution {
public:
  vector<bool> kidsWithCandies(vector<int> &a, int n) {
    vector<int> b(a);
    sort(b.begin(), b.end());
    vector<bool> ret(a.size());
    for (int i = 0; i < (int)a.size(); ++i) {
      ret[i] = upper_bound(b.begin(), b.end(), a[i] + n) == b.end();
    }
    return ret;
  }
};