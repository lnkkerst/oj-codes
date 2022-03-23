#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <cctype>
using namespace std;

int work(int x) {
    int ret = 1;
    do {
        ++ret;
        if(x & 1) x *= 3, ++x;
        else x >>= 1;
    } while(x != 1);
    return ret;
}

int main() {
    int l, r;
    while(scanf("%d%d", &l, &r) != EOF) {
        int ans = -1;
        for(int i = l; i <= r; ++i)
            ans = max(work(i), ans);
        printf("%d %d %d\n", l, r, ans);
    }
    return 0;
}