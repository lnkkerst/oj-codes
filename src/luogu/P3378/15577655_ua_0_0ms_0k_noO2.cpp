#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

priority_queue <int,vector<int>,greater<int> > a;

int main() {
    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {
        int e;

        scanf("%d", &e);

        if(e == 1) {
            int t;
            scanf("%d", &t);
            a.push(t);
        }
        else if(e == 2) {
            printf("%d\n", a.top());
            a.pop();
        }
        else
            a.pop();
    }

    return 0;
}