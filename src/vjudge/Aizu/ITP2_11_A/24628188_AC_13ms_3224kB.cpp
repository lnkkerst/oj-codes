#include <iostream>
using namespace std;

int n, cnt = 0;

int main() {
    cin >> n;
    for(int i = 0; i <= (1 << n) - 1; ++i) {
        printf("%d:", cnt++);
        int t = i, j = 0;
        do {
            if(t % 2) printf(" %d", j);
            t >>= 1, ++j;
        } while(t);
        puts("");
    }
    return 0;
}