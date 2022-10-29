bool cmp(const vector<int> &a, const vector<int> &b) {
  if (a[0] == b[0])
    return a[1] < b[1];
  return a[0] < b[0];
}

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &a) {
    if (!a.size())
      return a;
    vector<vector<int>> ret;
    sort(a.begin(), a.end(), cmp);
    int nl = a[0][0], nr = a[0][1];
    for (int i = 1; i < (int)a.size(); ++i) {
      if (a[i][0] <= nr)
        nr = max(nr, a[i][1]);
      else {
        ret.push_back({nl, nr});
        nl = a[i][0];
        nr = a[i][1];
      }
    }
    ret.push_back({nl, nr});
    return ret;
  }
};