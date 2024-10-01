class Solution {
public:
  string convert(string s, int numRows) {
    if (numRows == 1) {
      return s;
    }
    vector<vector<char>> ans;
    ans.resize(numRows);
    int now = 0, nex = -1;
    for (auto i : s) {
      ans[now].push_back(i);
      if (now == 0 || now == numRows - 1) {
        nex = -nex;
      }
      now += nex;
    }
    string ret;
    for (auto i : ans) {
      for (auto j : i) {
        ret.push_back(j);
      }
    }
    return ret;
  }
};
