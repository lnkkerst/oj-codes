class Solution {
public:
  int kthSmallest(vector<vector<int>> &mat, int k) {
    vector<int> ret(mat[0]);
    for (size_t i = 1; i < mat.size(); ++i) {
      vector<int> b;
      for (auto &j : ret)
        for (auto &k : mat[i])
          b.push_back(j + k);
      sort(b.begin(), b.end());
      ret.assign(b.begin(), b.end());
      ret.resize(min(k, (int)ret.size()));
    }
    return ret[k - 1];
  }
};