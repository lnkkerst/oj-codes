class Solution {
public:
  int game(vector<int> &guess, vector<int> &answer) {
    int ret = 0;
    for (int i = 0; i < 3; ++i) {
      ret += guess[i] == answer[i];
    }
    return ret;
  }
};
