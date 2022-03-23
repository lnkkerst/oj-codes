#include <cstdio>
#include <algorithm>
#include <cctype>
#include <queue>
#include <cstring>
#define MAXN 2000010
using namespace std;

struct Edge {
    int to, w;
} ;

vector<Edge > nodes[MAXN];
bool vis[MAXN];
int n, m;
int st, ed;
int dis[MAXN];

int read() {
    int ret, f = 1;
    char ch;
    while(!isdigit(ch = getchar())) (ch == '-') && (f = -1);
    for(ret = ch - '0'; isdigit(ch = getchar()); ret *= 10, ret += ch - '0');
    return ret * f;
}

void print(int x) {
    if(x < 0) putchar('-'), x = -x;
    if(x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

void addedge(int u, int v, int w) {
    nodes[u].push_back((Edge){v, w});
    nodes[v].push_back((Edge){u, w});
}

int dij(int s) {
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;
    priority_queue<pair<int , int > , vector<pair<int, int > > , greater<pair<int , int > > > heap;
    heap.push(make_pair(dis[s], s));
    while(!heap.empty()) {
        int u = heap.top().second;
        heap.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(vector<Edge >::iterator i = nodes[u].begin(); i != nodes[u].end(); ++i) {
            int v = i->to;
            if(dis[v] > dis[u] + i->w) {
                dis[v] = dis[u] + i->w;
                if(!vis[v]) heap.push(make_pair(dis[v], v));
            }
        }
    }
    return dis[ed];
}

signed main() {
    // freopen("in", "r", stdin);
    n = read(), m = read();
    st = (n - 1) * (m - 1) * 2 + 1, ed = (n - 1) * (m - 1) * 2 + 2;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m - 1; ++j) {
            int x = read();
            if(i == 1) addedge(st, j, x);
            else if(i == n) addedge((2 * (n - 1) - 1) * (m - 1) + j, ed, x);
            else addedge((2 * (i - 1) - 1) * (m - 1) + j, 2 * (i - 1) * (m - 1) + j, x);
        }
    for(int i = 1; i <= n - 1; ++i)
        for(int j = 1; j <= m; ++j) {
            int x = read();
            if(j == 1) addedge((i * 2 - 1) * (m - 1) + 1, ed, x);
            else if(j == m) addedge(st, 2 * i * (m - 1) - (m - 1), x);
            else addedge((i - 1) * 2 * (m - 1) + j - 1, ((i - 1) * 2 + 1) * (m - 1) + j, x);
        }
    for(int i = 1; i <= n - 1; ++i)
        for(int j = 1; j <= m - 1; ++j) {
            int x = read();
            addedge((i - 1) * 2 * (m - 1) + j, (i - 1) * 2 * (m - 1) + (m - 1) + j, x);
        }
    print(dij(st));
    return 0;
}