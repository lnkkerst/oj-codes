// https://blog.csdn.net/qq_45791939/article/details/122227315

#include <bits/stdc++.h>
using namespace std;

const int MAX_NUM = 2010;
const double INF = 1e8;
int N, S, P, T;
double t1;
double I_k[MAX_NUM / 2][MAX_NUM / 2];

struct node {
  double v, u, a, b, c, d;
  int count_put;
} Node[MAX_NUM / 2];

struct tuchu {
  int t;
  int D;
  double w;
  tuchu(int _t, double _w, int _D) {
    t = _t;
    w = _w;
    D = _D;
  }
};
vector<tuchu> G[MAX_NUM];

static unsigned long nnext = 1;
// RAND_MAX assumed to be 32767
int myrand(void) {
  nnext = nnext * 1103515245 + 12345;
  return ((unsigned)(nnext / 65536) % 32768);
}

int main() {
  std::ios::sync_with_stdio(false);
  cin >> N >> S >> P >> T;
  cin >> t1;

  int temp_N = N;
  int N_tmp = 0;
  while (temp_N > 0) {
    int RN;
    cin >> RN;
    temp_N -= RN;
    int RN_tmp = RN;
    double v, u, a, b, c, d;
    cin >> v >> u >> a >> b >> c >> d;
    while (RN_tmp > 0) {
      Node[N_tmp].v = v;
      Node[N_tmp].u = u;
      Node[N_tmp].a = a;
      Node[N_tmp].b = b;
      Node[N_tmp].c = c;
      Node[N_tmp].d = d;
      N_tmp++;
      RN_tmp--;
    }
  }

  int maic[MAX_NUM];
  int P_tmp = 0;
  int temp_P = P;
  while (temp_P > 0) {
    int r;
    cin >> r;
    maic[P_tmp + N] = r;
    P_tmp++;
    temp_P--;
  }

  int S_tmp = 0;
  int temp_S = S;
  int mod = 0;
  while (temp_S > 0) {
    int s, t, D;
    double w;
    cin >> s >> t >> w >> D;
    G[s].push_back(tuchu(t, w, D)); // 存储图
    mod = max(mod, D + 1);
    temp_S--;
    S_tmp++;
  }
  //-----------输入完毕-------------
  for (int i = 0; i < T; i++) {
    int t_tmp = i % mod;
    for (int j = N; j < P + N; j++) {
      if (maic[j] > myrand()) {
        for (int k = 0; k < G[j].size(); k++) // 遍历脉冲源j的连接的神经元
        {
          int node_get = G[j][k].t; // 脉冲源j的连接的神经元
          double w_tmp = G[j][k].w;
          int D_tmp = G[j][k].D;
          I_k[(t_tmp + D_tmp) % mod][node_get] += w_tmp;
        }
      }
    }

    for (int j = 0; j < N; j++) {
      double v_tmp = Node[j].v;
      double u_tmp = Node[j].u;
      double a_tmp = Node[j].a;
      double b_tmp = Node[j].b;
      double c_tmp = Node[j].c;
      double d_tmp = Node[j].d;
      Node[j].v = v_tmp + t1 * (0.04 * v_tmp * v_tmp + 5 * v_tmp + 140 - u_tmp)
                  + I_k[t_tmp][j];
      Node[j].u = u_tmp + t1 * a_tmp * (b_tmp * v_tmp - u_tmp);
      if (Node[j].v >= 30) {
        Node[j].v = c_tmp;
        Node[j].u += d_tmp;
        Node[j].count_put++;
        for (int k = 0; k < G[j].size(); k++) // 遍历脉冲源j的连接的神经元
        {
          int node_get = G[j][k].t; // 脉冲源j的连接的神经元
          double w_tmp = G[j][k].w;
          int D_tmp = G[j][k].D;
          I_k[(t_tmp + D_tmp) % mod][node_get] += w_tmp;
        }
      }
    }
    memset(I_k[t_tmp], 0, sizeof I_k[t_tmp]);
  }

  double max_v = -INF;
  double min_v = INF;
  int max_count = -INF;
  int min_count = INF;
  for (int i = 0; i < N; i++) {
    max_v = max(max_v, Node[i].v);
    min_v = min(min_v, Node[i].v);
    max_count = max(max_count, Node[i].count_put);
    min_count = min(min_count, Node[i].count_put);
  }
  cout << setiosflags(ios::fixed) << setprecision(3) << min_v << " " << max_v
       << endl;
  cout << min_count << " " << max_count << endl;
  return 0;
}
