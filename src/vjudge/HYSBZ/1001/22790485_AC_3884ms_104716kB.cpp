#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cctype>
#include <vector>
#include <cstring>
using namespace std;
inline void read(int &x)
{
    x = 0;
    char c = getchar();
    while (!isdigit(c))
        c = getchar();
    while (isdigit(c))
        x = x * 10 + c - '0', c = getchar();
}
#define MAXN 2000010
struct node
{
    int to, va;
    node(int a, int b) { to = a, va = b; }
};
vector<node> v[MAXN];
inline void add_edge(int f, int t, int w)
{
    v[f].push_back(node(t, w));
    v[t].push_back(node(f, w));
}
bool vis[MAXN];
int st, ed;
int dis[MAXN];
int SPFA()
{
    memset(dis, 0x3f, sizeof dis);
    vis[st] = 1;
    queue<int> q;
    q.push(st);
    dis[st] = 0;
    while (!q.empty())
    {
        int tmp = q.front();
        q.pop();
        vis[tmp] = 0;
        for (int i = 0; i < v[tmp].size(); ++i)
        {
            int o = v[tmp][i].to;
            if (dis[o] > dis[tmp] + v[tmp][i].va)
            {
                dis[o] = dis[tmp] + v[tmp][i].va;
                if (!vis[o])
                    q.push(o), vis[o] = 1;
            }
        }
    }
    return dis[ed];
}
int n, m;
inline void getheng(int i, int j, int k)
{
    if (i == 1)
        add_edge(st, j, k);
    else if (i == n)
        add_edge((2 * (n - 1) - 1) * (m - 1) + j, ed, k);
    else
        add_edge((2 * (i - 1) - 1) * (m - 1) + j, 2 * (i - 1) * (m - 1) + j, k);
}
inline void getshu(int i, int j, int k)
{
    if (j == 1)
        add_edge((i * 2 - 1) * (m - 1) + 1, ed, k);
    else if (j == m)
        add_edge(st, 2 * i * (m - 1) - (m - 1), k);
    else
        add_edge((i - 1) * 2 * (m - 1) + j - 1, ((i - 1) * 2 + 1) * (m - 1) + j, k);
}
inline void getxie(int i, int j, int k)
{
    add_edge((i - 1) * 2 * (m - 1) + j, (i - 1) * 2 * (m - 1) + (m - 1) + j, k);
}
int main()
{
    read(n), read(m);
    st = (n - 1) * (m - 1) * 2 + 1, ed = (n - 1) * (m - 1) * 2 + 2;
    int x;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j < m; ++j)
            read(x), getheng(i, j, x);
    }
    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j <= m; ++j)
            read(x), getshu(i, j, x);
    }
    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j < m; ++j)
            read(x), getxie(i, j, x);
    }
    cout << SPFA() << endl;
    return 0;
}