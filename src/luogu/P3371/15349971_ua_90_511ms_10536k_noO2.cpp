#include <cstdio>
#define MAXN 10005
#define MAXM 500005

int main() {
    int n, m, s;
    int u[MAXM], v[MAXM], w[MAXM];
    int first[MAXN], next[MAXM];
    int dis[MAXN] = {0}, book[MAXN] = {0};
    int que[MAXM] = {0}, h = 1, t = 1;

    const int inf = 99999999;

    scanf("%d%d%d", &n, &m, &s);

    for(int i = 1; i <= n; i++)
        dis[i] = inf;

    dis[s] = 0;

    for(int i = 1; i <= n; i++)
        book[i] = 0;

    for(int i = 1; i <= n; i++)
        first[i] = -1;

    for(int i = 1; i <= m; i++) {
        scanf("%d%d%d", &u[i], &v[i], &w[i]);

        next[i] = first[u[i]];
        first[u[i]] = i;
    }

    que[t] = s;
    t++;
    book[s] = 1;

    while(h < t) {
        int k = first[que[h]];
        while(k != -1) {
            if(dis[v[k]] > dis[u[k]] + w[k]) {
                dis[v[k]] = dis[u[k]] + w[k];

                if(book[v[k]] == 0) {
                    que[t] = v[k];
                    t++;
                    book[v[k]] = 1;
                }
            }

            k = next[k];
        }

        book[que[h]] = 0;
        h++;
    }

    for(int i = 1; i <= n; i++)
        printf("%d ", dis[i]);

    return 0;
}