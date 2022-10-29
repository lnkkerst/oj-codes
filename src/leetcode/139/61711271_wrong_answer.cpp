class Solution {
public:
  bool wordBreak(string s, vector<string> &wordDict) {
    unordered_map<string, bool> b;
    for (auto i : wordDict)
      b[i] = 1;
    string now;
    for (auto i : s) {
      now.push_back(i);
      if (b[now])
        now.clear();
    }
    return !now.size();
  }
};