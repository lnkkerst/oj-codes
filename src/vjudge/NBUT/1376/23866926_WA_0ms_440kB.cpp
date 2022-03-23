#include <cstdio>

int a[110], n, x;
bool fl = 1;

int main() {
    while(scanf("%d", &n) != EOF) {
        if(!fl) putchar('\n');
        fl = 0;
        for(int i = 0; i <= 100; ++i) a[i] = 0;
        for(int i = 1; i <= n; ++i) scanf("%d", &x), ++a[x];
        for(int i = 0; i <= 100; ++i)
            while(a[i]--) printf("%d ", i);
    }
    return 0;
}