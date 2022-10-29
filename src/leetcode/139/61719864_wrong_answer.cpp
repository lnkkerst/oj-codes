bool cmp(const string &a, const string &b) { return a.length() > b.length(); }
class Solution {
public:
  bool wordBreak1(string s, vector<string> &wordDict) {
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
  bool wordBreak2(string s, vector<string> &wordDict) {
    sort(wordDict.begin(), wordDict.end(), cmp);
    for (auto i : wordDict) {
      int pos = s.find(i);
      while (pos != string::npos) {
        s.erase(pos, i.length());
        pos = s.find(i);
      }
    }
    return !s.length();
  }
  bool wordBreak(string s, vector<string> &wordDict) {
    return wordBreak1(s, wordDict) || wordBreak2(s, wordDict);
  }
};