class Solution {
public:
  string destCity(vector<vector<string>> &paths) {
    unordered_map<string, string> b;
    for (auto &i : paths) {
      b[i[0]] = i[1];
    }
    string ret = paths[0][0];
    while (1) {
      if (b.find(ret) == b.end()) {
        return ret;
      }
      ret = b[ret];
    }
  }
};