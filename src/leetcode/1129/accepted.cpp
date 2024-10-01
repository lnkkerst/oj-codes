#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<pair<int, int>>> a;
  vector<vector<int>> ans;

  void addEdge(int u, int v, int color) {
    a[u].emplace_back(make_pair(v, color));
  }

  void dfs(int cur, int last) {
    for (auto &i : a[cur]) {
      if (last ^ i.second) {
        if (ans[i.first][last ^ 1] == -1
            || ans[i.first][last ^ 1] > ans[cur][last] + 1) {
          ans[i.first][last ^ 1] = ans[cur][last] + 1;
          dfs(i.first, i.second);
        }
      }
    }
  }

  vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges,
                                       vector<vector<int>> &blueEdges) {
    a.resize(n);
    ans.resize(n);
    fill(ans.begin(), ans.end(), vector<int>{-1, -1});
    ans[0] = {0, 0};

    for (auto &i : redEdges) {
      this->addEdge(i[0], i[1], 0);
    }

    for (auto &i : blueEdges) {
      this->addEdge(i[0], i[1], 1);
    }

    for (int i = 0; i < n; ++i) {
      dfs(0, 1);
      dfs(0, 0);
    }

    vector<int> res;
    for (auto &i : ans) {
      if (i[0] == -1) {
        res.emplace_back(i[1]);
      } else if (i[1] == -1) {
        res.emplace_back(i[0]);
      } else {
        res.emplace_back(min(i[0], i[1]));
      }
    }

    return res;
  }
};
