#include <cstdio>

int n, m, tree[500010] = {0};

int lowbit(int x) {
    return x & -x;
}

void add(int x, int y) {
    for(; x <= n; x += lowbit(x))
        tree[x] += y;
}

int find(int x) {
    int res = 0;
    for(; x; x -= lowbit(x))
        res += tree[x];
    return res;
}

int main() {
    int a, b = 0;
    scanf("%d%d", &n, &m);

    for(int i = 1; i <= n; i++) {
        scanf("%d", &a);
        add(i, a - b);
        b = a;
    }
    
    for(int i = 1; i <= m; i++) {
        int t;
        scanf("%d", &t);
        if(t == 1){
            int x, y, k;
            scanf("%d%d%d", &x, &y, &k);
            add(x, k);
            add(y + 1, -k);
        }
        else {
            int x;
            scanf("%d", &x);
            printf("%d\n", find(x));
        }
    }
    
    return 0;
}