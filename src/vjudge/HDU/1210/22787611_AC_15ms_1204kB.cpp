#include <cstdio>

int work(int x) {
    int i = 1, ret = 0;
    do i = (i * 2) % (x * 2 + 1);
    while(++ret, i != 1);
    return ret;
}

int main() {
    int x;
    while(scanf("%d", &x) != EOF)
        printf("%d\n", work(x));
    return 0;
}