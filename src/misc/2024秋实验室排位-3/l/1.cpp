#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

#define int long long

void solve() {
  deque<int> pile;
  for (int i = 1; i <= 98; ++i) {
    int x;
    cin >> x;
    pile.emplace_back(x);
  }
  deque<int> hand;
  deque<deque<int>> rows(4);
  rows[0] = {1};
  rows[1] = {1};
  rows[2] = {100};
  rows[3] = {100};

  auto out_ans = [&]() {
    for (int i = 0; i < 4; ++i) {
      for (auto x : rows[i]) {
        cout << x << ' ';
      }
      cout << endl;
    }
    for (auto i : hand) {
      cout << i << ' ';
    }
    cout << endl;
    for (auto i : pile) {
      cout << i << ' ';
    }
    cout << endl;
  };

  int tround = 0;

  while (true) {
    // cout << "round: " << ++tround << endl;
    while (!pile.empty() && hand.size() < 8) {
      hand.emplace_back(pile.front());
      pile.pop_front();
    }

    // cout << "hand: ";
    // for (auto i : hand) {
    //   cout << i << ' ';
    // }
    // cout << endl;

    deque<int> del(8);
    int cnt = 0;

    while (cnt < 2) {

      for (int i = 0; i < hand.size() && cnt < 2; ++i) {
        if (del[i]) {
          continue;
        }
        for (int j = 0; j < 4 && cnt < 2; ++j) {
          if (((j < 2 && hand[i] < rows[j].back())
               || (j >= 2 && (hand[i] > rows[j].back())))
              && abs(rows[j].back() - hand[i]) == 10) {
            rows[j].emplace_back(hand[i]);
            del[i] = true;
            ++cnt;
            i = -1;
            break;
          }
        }
      }

      // calc min
      int mi = 1e9;
      for (int i = 0; i < hand.size() && cnt < 2; ++i) {
        if (del[i]) {
          continue;
        }

        for (int j = 0; j < 2 && cnt < 2; ++j) {
          if (rows[j].back() < hand[i]) {
            mi = min(mi, hand[i] - rows[j].back());
          }
        }
        for (int j = 2; j < 4 && cnt < 2; ++j) {
          if (rows[j].back() > hand[i]) {
            mi = min(mi, rows[j].back() - hand[i]);
          }
        }
      }

      // cout << "mi: " << mi << endl;

      if (mi == (int)1e9) {
        break;
      }

      bool fl = true;
      for (int i = 0; i < hand.size() && cnt < 2 && fl; ++i) {
        if (del[i]) {
          continue;
        }

        for (int j = 0; j < 2 && cnt < 2 && fl; ++j) {
          if (rows[j].back() < hand[i]) {
            if (hand[i] - rows[j].back() == mi) {
              rows[j].emplace_back(hand[i]);
              del[i] = true;
              ++cnt;
              fl = false;
              i = -1;
              break;
            }
          }
        }
        for (int j = 2; j < 4 && cnt < 2 && fl; ++j) {
          if (rows[j].back() > hand[i]) {
            if (rows[j].back() - hand[i] == mi) {
              rows[j].emplace_back(hand[i]);
              del[i] = true;
              ++cnt;
              fl = false;
              i = -1;
              break;
            }
          }
        }
      }
    }

    decltype(hand) n_hand;
    for (int i = 0; i < hand.size(); ++i) {
      if (!del[i]) {
        n_hand.emplace_back(hand[i]);
      }
    }
    hand = n_hand;

    // out_ans();
    // cout << endl;

    if (cnt != 2) {
      out_ans();
      return;
    }
  }
  out_ans();
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
}
