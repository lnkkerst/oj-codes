// #include <bits/stdc++.h>
// #define MAXN 10086
// using namespace std;

// struct Node {
//     struct Edge *head;
//     int dis;
// } ;

// struct Edge {
//     Node *v;
//     int w;
//     Edge *nex;
// } ;

// vector<Edge > edges;
// vector<Node> nodes;

// int dis[MAXN], n, m, s;

// int read() {
//     int ret;
//     char ch;
//     bool flag = 0;
//     while(!isdigit(ch = getchar())) (ch == '-') && (flag = true);
//     for(ret = ch - '0'; isdigit(ch = getchar()); ret = ret * 10 + ch - '0');
//     return flag ? -ret : ret;
// }

// void addedges(int u, int v,int w) {
//     edges.push_back((Edge){&nodes[v], w, nodes[u].head});
//     nodes[u].head = &edges.back();
// }

// void dij(int start) {
//     set<pair<int, Node* > > heap;
//     nodes[start].dis = 0;
//     for(int i = 1; i <= n; ++i) heap.insert(make_pair(nodes[i].dis,
//     &nodes[i])); while(heap.size()) {
//         int d = heap.begin()->first;
//         Node *u = heap.begin()->second;
//         heap.erase(heap.begin());
//         if(d > u->dis) continue;
//         for(Edge *i = u->head; i != NULL; i = i->nex) {
//             printf("ok\n");
//             if(u->dis + i->w < i->v->dis) {
//                 i->v->dis = u->dis + i->w;
//                 heap.insert(make_pair(i->v->dis, i->v));
//             }
//         }
//     }
// }

// int main() {
//     n = read(), m = read(), s = read();
//     for(int i = 0; i <= n; ++i) nodes.push_back((Node){NULL, 0x3f});
//     for(int i = 1; i <= m; ++i) addedges(read(), read(), read());
//     dij(s);
//     for(int i = 1; i <= n; ++i) printf("%d", nodes[i].dis);
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// struct Edge {
//     int v, w, nex;
// } edges[10086 << 1];

// struct Node {
//     int dis, head;
// } nodes[10086];

// int n, m, s, cnt;

// int read() {
//     int ret;
//     bool flag = 0;
//     char ch;
//     while(!isdigit(ch = getchar())) (ch == '-') && (flag = 1);
//     for(ret = ch - '0'; isdigit(ch = getchar()); ret *= 10, ret += ch - '0');
//     return flag ? -ret : ret;
// }

// void addedge(int u, int v, int w) {
//     edges[++cnt] = (Edge){v, w, nodes[u].head};
//     nodes[u].head = cnt;
// }

// void dij(int start) {
//     for(int i = 1; i <= n; ++i) nodes[i].dis = 63;
//     set<pair<int, int> > heap;

//     nodes[start].dis = 0;
//     for(int i = 1; i <= n; ++i) heap.insert(make_pair(nodes[i].dis, i));
//     while(heap.size() > 0) {
//         int d = heap.begin()->first;
//         int u = heap.begin()->second;
//         heap.erase(heap.begin());
//         if(d > nodes[u].dis) continue;
//         for(int i = nodes[u].head; i != -1; i = edges[i].nex)
//             if(nodes[u].dis + edges[i].w < nodes[edges[i].v].dis) {
//                 nodes[edges[i].v].dis = nodes[u].dis + edges[i].w;
//                 heap.insert(make_pair(nodes[edges[i].v].dis,
//                 edges[i].v));printf("ok\n");
//             }
//     }
// }

// int main() {
//     n = read(), m = read(), s = read();
//     for(int i = 0; i <= m + n; ++i) nodes[i].head = -1;
//     for(int i = 1; i <= m; ++i) addedge(read(), read(), read());
//     dij(s);
//     for(int i = 1; i <= n; ++i) printf("%d ", nodes[i].dis);
//     return 0;
// }

#include <cstdio>

struct Edge {
  int v, w, nex;
} edges[200010];

struct Heap {
  struct Mem {
    int f, s;
  } mem[400010];
  int cnt;
  Heap() {
    cnt = 0;
  }
  void swap(int x, int y) {
    int t = mem[x].f;
    mem[x].f = mem[y].f, mem[y].f = t;
    t = mem[x].s, mem[x].s = mem[y].s, mem[y].s = t;
  }
  void update(int x) {
    while (mem[x].f < mem[x >> 1].f) {
      swap(x, x >> 1), x >>= 1;
    }
  }
  void pushdown(int i) {
    if (i << 1 > cnt) {
      return;
    }
    int t = i << 1;
    if (t < cnt && mem[t | 1].f > mem[t].f) {
      t |= 1;
    }
    if (mem[t].f < mem[i].f) {
      swap(t, i);
      pushdown(t);
    }
  }
  void insert(int x, int y) {
    mem[++cnt] = (Mem){x, y};
    if (cnt != 1) {
      update(cnt);
    }
  }
  void pop() {
    mem[1].f = mem[cnt].f, mem[1].s = mem[cnt].s;
    cnt--;
    pushdown(1);
  }
};

int n, m, s, dis[100861], h[100861], cnt;
bool vis[100861];

bool isdigit(char ch) {
  return (ch <= '9' && ch >= '0');
}

int read() {
  int ret;
  bool flag = 0;
  char ch;
  while (!isdigit(ch = getchar())) {
    (ch == '-') && (flag = 1);
  }
  for (ret = ch - '0'; isdigit(ch = getchar()); ret *= 10, ret += ch - '0')
    ;
  return flag ? -ret : ret;
}

void addedge(int u, int v, int w) {
  ++cnt;
  edges[cnt].v = v;
  edges[cnt].w = w;
  edges[cnt].nex = h[u];
  h[u] = cnt;
}

void dij(int s) {
  for (int i = 1; i <= n; ++i) {
    dis[i] = (int)1e9;
  }
  dis[s] = 0;
  Heap heap;
  heap.insert(dis[s], s);
  while (heap.cnt > 0) {
    int u = heap.mem[1].s;
    heap.pop();
    if (vis[u]) {
      continue;
    }
    vis[u] = 1;
    for (int i = h[u]; i; i = edges[i].nex) {
      if (dis[edges[i].v] > dis[u] + edges[i].w) {
        dis[edges[i].v] = dis[u] + edges[i].w;
        if (!edges[i].v) {
          heap.insert(dis[edges[i].v], edges[i].v);
        }
      }
    }
  }
}

int main() {
  n = read(), m = read(), s = read();
  for (int i = 1; i <= m; ++i) {
    int u = read(), v = read(), w = read();
    addedge(u, v, w);
  }
  dij(s);
  for (int i = 1; i <= n; ++i) {
    printf("%d ", dis[i]);
  }
  return 0;
}
