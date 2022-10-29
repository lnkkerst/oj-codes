class Solution {
public:
  unordered_map<string, int> b;
  vector<string> srv;
  bool pd(const string &s) {
    if (!s.size())
      return 0;
    for (int i = 0, j = s.size() - 1; i < j; ++i, --j) {
      if (s[i] != s[j])
        return 0;
    }
    return 1;
  }
  vector<vector<int>> palindromePairs(vector<string> &words) {
    vector<vector<int>> ret;
    for (int i = 0; i < words.size(); ++i) {
      srv.push_back(words[i]);
      reverse(srv.back().begin(), srv.back().end());
      b[srv[i]] = i;
    }
    for (int i = 0; i < words.size(); ++i) {
      for (int j = 0; j < words[i].size(); ++j) {
        if (pd(words[i].substr(j, words[i].size() - j + 1))) {
          auto it = b.find(words[i].substr(0, j));
          if (it != b.end())
            ret.push_back({i, it->second});
        }
        if (pd(words[i].substr(0, j))) {
          auto it = b.find(words[i].substr(j, words[i].size() - j + 1));
          if (it != b.end())
            ret.push_back({it->second, i});
        }
      }
    }
    return ret;
  }
};