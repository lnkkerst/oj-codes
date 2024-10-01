class Solution {
public:
  string largestNumber(vector<int> &cost, int target) {
    string dp[5010];
    // fill(begin(dp), end(dp), "0");
    // string ans[5010];
    unordered_map<int, int> b;
    for (int i = 0; i < 9; ++i) {
      b[cost[i]] = i + 1;
    }
    for (int i = 1; i <= target; ++i) {
      // cout << i << endl;
      for (auto j : b) {
        if (i >= j.first) {
          string nex = dp[i - j.first] + string(1, j.second + '0');
          // cout << nex << ' ' << i - j.first << ' ' << j.first << '
          // ' << j.second << endl;
          int tot = 0;
          for (auto k : nex) {
            tot += cost[k - '0' - 1];
          }
          if (tot == i) {
            if (nex.length() > dp[i].length()) {
              dp[i] = nex;
            } else if (nex.length() == dp[i].length()) {
              if (nex > dp[i]) {
                dp[i] = nex;
              }
            }
          }
        }
      }
      // cout << dp[i] << endl;
    }
    // string ret;
    // vector<pair<int, int> > a;
    // unordered_map<int, int> b, br;
    // for(int i = 0; i < 9; ++i) b[cost[i]] = i + 1;
    // // for(int i = 0; i < 9; ++i) a.push_back(make_pair(i + 1, cost[i])
    // for(const auto &i : b) a.push_back(make_pair(i.second, i.first));
    // sort(a.begin(), a.end(), [](const pair<int, int> &aa, const pair<int,
    // int> &bb)->bool{
    //     if(aa.second == bb.second) return aa.first > bb.first;
    //     return aa.second < bb.second;
    // });
    // int now = 0;
    // while(now + a.front().second < target) now += a.front().second,
    // ret.push_back(a.front().first + '0'); while(now != target) {
    //     if(ret.empty()) return "0";
    //     now -= ret.back() - '0';
    //     ret.pop_back();
    //     if(b[target - now]) ret.push_back(b[target - now] + '0'), now +=
    //     target; else {
    //         for(auto i = cost.rbegin(), i != cost.rend(); ++i) {
    //             if(*i)
    //         }
    //         if(k == a.end() || k == a.begin()) return "0";
    //         else ret.push_back((k - 1)->first + '0'), now += (k -
    //         1)->second;
    //     }
    // }
    // return ret;
    return dp[target];
  }
};
