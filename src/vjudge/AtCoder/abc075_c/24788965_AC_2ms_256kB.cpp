// #include <iostream>
// using namespace std;

// struct Node {
//     int h;
// } nodes[233];

// struct Edge {
//     int to, nex;
// } edges[2333];

// int n, m, ans, cnt;

// void addedge(int u, int v) {
//     edges[++cnt] = {v, nodes[u].h};
//     nodes[u].h = cnt;
// }

// int main() {
//     cin >> n >> m;
//     for(int i = 1; i <= m; ++i) {
//         int u, v;
//         cin >> u >> v;
//         addedge(u, v);
//         addedge(v, u);
//     }
//     for(int i = 1; i <= )
// }

#include <iostream>
#include <cstring>
using namespace std;

int n, m, e[51][51], ans, u[51 << 1], v[51 << 1];
bool vis[51];

void dfs(int node) {
    vis[node] = 1;
    for(int i = 1; i <= n; ++i) {
        if(i == node) continue;
        if(!vis[i] && e[node][i]) dfs(i);
    }
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        cin >> u[i] >> v[i];
        e[u[i]][v[i]] = e[v[i]][u[i]] = 1;
    }
    for(int i = 1; i <= m; ++i) {
        e[u[i]][v[i]] = e[v[i]][u[i]] = 0;
        memset(vis, 0, sizeof(vis));
        dfs(1);
        for(int i = 1; i <= n; ++i)
            if(!vis[i]) {
                ++ans;
                break;
            }
        e[u[i]][v[i]] = e[v[i]][u[i]] = 1;
    }
    cout << ans;
    return 0;
}