class Solution {
public:
  int numJewelsInStones(string J, string S) {
    unordered_map<char, bool> b;
    for (auto i : J) {
      b[i] = 1;
    }
    int ret = 0;
    for (auto i : S) {
      ret += b[i];
    }
    return ret;
  }
};
