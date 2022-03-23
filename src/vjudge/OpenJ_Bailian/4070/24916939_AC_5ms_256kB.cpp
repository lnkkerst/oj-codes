#include <iostream>
#include <algorithm>
using namespace std;

int a[10], n;

int main() {
    while(cin >> n) {
        if(!n) return 0;
        for(int i = 1; i <= n; ++i) a[i] = i;
        do {
            for(int i = 1; i <= n; ++i)
                cout << a[i] << ' ';
            puts("");
        } while(next_permutation(a + 1, a + n + 1));
    }
    return 0;
}