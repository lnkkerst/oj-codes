#include <cstdio>
#include <cctype>
#define num ch - '0'
#define MAXN 100010

int n, m, tree[MAXN], a[MAXN];
bool pd[MAXN];
const int lcn[]={4,7,44,47,74,77,444,447,474,744,477,747,774,777,4444,4447,4474,4744,7444,4477,4747,7447,4774,7474,7744,4777,7477,7747,7774,7777};

int read() {
    int res;
    char ch;
    bool flag = 0;
    while(!isdigit(ch = getchar()))
        (ch == '-') && (flag = true);
    for(res = num; isdigit(ch = getchar()); res = res * 10 + num);
    (flag) && (res =-res);
    return res;
}

void print(int x) {
    if(x < 0) {
        putchar('-');
        x = -x;
    }
    if(x > 9)
        print(x / 10);
    putchar(x % 10 + '0');
}

int lowbit(int x) {
    return x & -x;
}

void add(int x, int y) {
    for(; x <= n; x += lowbit(x))
        tree[x] += y;
}

int find(int x) {
    int res = 0;
    for(; x > 0; x -= lowbit(x))
        res += tree[x];
    return res;
}

int main() {
    for(int i = 0; i < 30; i++)
        pd[lcn[i]] = 1;

    n = read();
    m = read();
    for(int i = 1; i <= n; i++) {
        a[i] = read();
        if(pd[a[i]])
            add(i, 1);
    }

    char e[6];
    
    for(int i = 1; i <= m; i++) {
        scanf("%s", e);
        if(e[0] == 'a'){
            int l, r, val;
            l = read();
            r = read();
            val = read();
            for(int j = l; j <= r; j++) {
                if(pd[a[j]])
                    add(j, -1);
                a[j] += val;
                if(pd[a[j]])
                    add(j, 1);
            }
        }
        else {
            int l, r;
            l = read();
            r = read();
            print(find(r) - find(l - 1));
            putchar('\n');
        }
    }
    
    return 0;
}