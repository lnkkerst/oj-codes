#pragma GCC optimize(2) // 开 O2 优化，STL 重灾区

#include <iostream>
#include <set> // 明星选手
#include <unordered_map>
#include <vector>

using namespace std;

#define int long long // 额度会爆 int，这里偷个懒

struct Node {
  int v, w; // 单个节点，ｖ 储存目标机器，w 储存额度

  Node(int _v, int _w): v(_v), w(_w) {}

  // 排序根据题目要求，额度作为第一关键字升序，编号作为第二关键字降序
  bool operator<(const Node &b) const {
    if (this->w == b.w) {
      return this->v < b.v;
    }
    return this->w > b.w;
  }
};

struct Req {   // 用来储存修改额度的请求
  int u, v, x; // 和题目所述意义相同

  Req(int _u, int _v, int _x): u(_u), v(_v), x(_x) {}
};

int n, m;                 // 含义如题
vector<multiset<Node>> a; // 每台机器的伪平衡树
vector<unordered_map<int, decltype(a.front().begin())>>
  b; // b[u][v] 储存机器 u 到机器 v 的额度在 a 中的迭代器（如果存在）
vector<vector<Req>> de; // de[i] 储存第 i 天失效的请求
int cntSingle, cntPair; // 储存通信孤岛和通信对的数量

// 查询机器 u 的主要通信对象
Node query(int u) {
  if (a[u].empty()) {
    return {0, 0};
  }
  return *(a[u].begin());
}

// 查询机器 u 是否在通信对里
bool hasPair(int u) {
  int v = query(u).v;
  if (v == 0) {
    return false;
  }
  return query(v).v == u;
}

// 给机器 u 到机器 v 的通信额度增加 x （单向）
void add(int u, int v, int x) {
  if (a[u].empty()) {
    --cntSingle; // u 为通信孤岛时，add 操作后它一定不是通信孤岛
  }
  if (hasPair(u)) {
    --cntPair; // 先把 u 从通信对里去除，操作结束后再看看是不是还在通信对里
  }
  auto it = b[u].find(v); // 找储存 u 和 v 通信额度的节点
  if (it != b[u].end()) { // 找到了，修改
    auto bf = (it->second)->w;
    a[u].erase(it->second);
    b[u].erase(it);
    if (bf + x != 0) { // 额度不为 0 的时候才把节点插入 multiset
      b[u][v] = a[u].insert(Node(v, bf + x));
    }
  } else { // 没找到，直接插入 multiset
    b[u][v] = a[u].insert(Node(v, x));
  }
  if (a[u].empty()) {
    ++cntSingle; // 若 add 操作后 u 没有任何通信额度，那它一定是新增的通信孤岛
  }
  if (hasPair(u)) {
    ++cntPair;
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  a.resize(n + 1);
  b.resize(n + 1);
  de.resize(m + 1);
  cntSingle = n;
  for (int t = 1; t <= m; ++t) {
    for (const auto &i : de[t]) { // 处理失效的请求
      add(i.u, i.v, -i.x);        // 两边都要减
      add(i.v, i.u, -i.x);
    }
    int k;
    cin >> k;
    for (int i = 1; i <= k; ++i) {
      int u, v, x, y;
      cin >> u >> v >> x >> y;
      add(u, v, x); // 两边都要加
      add(v, u, x);
      if (t + y <= m) { // 会用到的失效请求才记录
        de[t + y].emplace_back(Req(u, v, x));
      }
    }
    int l; // 以下含义如题
    cin >> l;
    for (int i = 1; i <= l; ++i) {
      int u;
      cin >> u;
      cout << query(u).v << endl;
    }
    int p, q;
    cin >> p >> q;
    if (p) {
      cout << cntSingle << endl;
    }
    if (q) {
      cout << cntPair << endl;
    }
  }
  return 0;
}
