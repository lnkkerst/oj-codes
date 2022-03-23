#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

priority_queue <int,vector<int>,greater<int> > a;

struct cmp {
    bool operator()(int &a, int &b) {
        return a > b;
    }
};

int main() {
    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {
        int t;
        scanf("%d", &t);
        a.push(t);
    }

    for(int i = 1; i <= n; i++) {
        printf("%d ", a.top());
        a.pop();
    }

    return 0;
}