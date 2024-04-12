// https://ccf-csp-project.github.io/CSP-Project-with-MkDocs/problem/23/3/1/#100

#pragma GCC optimize("O2")
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 2010;
const int maxD = 2010;

// 如果使用原题的 next 可能会 CE，这里改成 nxt
static unsigned long nxt = 1;
/* RAND_MAX assumed to be 32767 */
int myrand(void) {
  nxt = nxt * 1103515245 + 12345;
  return ((unsigned)(nxt / 65536) % 32768);
}

int N, S, P, T;
double dt;
// 脉冲源只需要 r 参数即可
int r[maxn];

// 神经元
struct Neuron {
  double v, u, a, b, c, d;
  int activate_times;
} neuron[maxn << 1];

// 突触
struct Synapse {
  int s, t;
  double w;
  int D;
} synapse[maxn << 1];

// 存图
vector<int> G[maxn << 1];
// 存储每个时刻每个节点的 Ik 值
double I[maxD][maxn << 1];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> N >> S >> P >> T;
  cin >> dt;
  int cur = 0, rn;
  double ru, rv, ra, rb, rc, rd;
  while (cur < N) {
    cin >> rn;
    cin >> rv >> ru >> ra >> rb >> rc >> rd;
    while (rn--) {
      neuron[cur].v = rv;
      neuron[cur].u = ru;
      neuron[cur].a = ra;
      neuron[cur].b = rb;
      neuron[cur].c = rc;
      neuron[cur].d = rd;
      neuron[cur].activate_times = 0;
      ++cur;
    }
  }
  for (int i = 0; i < P; ++i) {
    cin >> r[i];
  }
  for (int i = 0; i < S; ++i) {
    cin >> synapse[i].s >> synapse[i].t;
    cin >> synapse[i].w;
    cin >> synapse[i].D;
    // 连边
    G[synapse[i].s].push_back(i);
  }

  // 按时间递增
  for (int t = 0; t < T; ++t) {
    // 滚动数组清零
    // for (int i = 0; i < N; ++i) {
    //   I[(t - 1 + maxD) % maxD][i] = 0;
    // }
    memset(I[(t - 1 + maxD) % maxD], 0, sizeof I[(t - 1 + maxD) % maxD]);
    // 脉冲源
    for (int i = 0; i < P; ++i) {
      if (r[i] > myrand()) {
        // 脉冲激发
        for (int j = 0; j < G[N + i].size(); ++j) {
          Synapse tmps = synapse[G[N + i][j]];
          I[(t + tmps.D) % maxD][tmps.t] += tmps.w;
        }
      }
    }
    // 神经元
    for (int i = 0; i < N; ++i) {
      double u = neuron[i].u, v = neuron[i].v;
      neuron[i].v = v + dt * (0.04 * v * v + 5 * v + 140 - u) + I[t % maxD][i];
      neuron[i].u = u + dt * neuron[i].a * (neuron[i].b * v - u);
      if (neuron[i].v >= 30) {
        // 脉冲激发
        neuron[i].v = neuron[i].c;
        neuron[i].u += neuron[i].d;
        ++neuron[i].activate_times;
        for (int j = 0; j < G[i].size(); ++j) {
          Synapse tmps = synapse[G[i][j]];
          I[(t + tmps.D) % maxD][tmps.t] += tmps.w;
        }
      }
    }
  }

  // 输出结果
  double minv = 1e18, maxv = -1e18;
  int mint = 1e9, maxt = 0;
  for (int i = 0; i < N; ++i) {
    if (neuron[i].v < minv) {
      minv = neuron[i].v;
    }
    if (neuron[i].v > maxv) {
      maxv = neuron[i].v;
    }
    if (mint > neuron[i].activate_times) {
      mint = neuron[i].activate_times;
    }
    if (maxt < neuron[i].activate_times) {
      maxt = neuron[i].activate_times;
    }
  }
  cout << fixed << setprecision(3) << minv << ' ' << maxv << endl;
  cout << mint << ' ' << maxt << endl;
  return 0;
}
