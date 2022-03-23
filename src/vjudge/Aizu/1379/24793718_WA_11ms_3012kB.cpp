#include <iostream>
#include <vector>
using namespace std;

struct Point {
    int x, y;
    bool vis;
} a[17];

struct Line {
    int x, y;
} ;

int n, ans;
vector<Line > q;

void dfs(int pt) {
    if(pt >= n) {
        int tmp = 0;
        for(auto i = q.begin(); i != q.end(); ++i)
            for(auto j = i + 1; j != q.end(); ++j)
                if(i->x * j->y == i->y * j->x) ++tmp;
        ans = max(ans, tmp);
        return ;
    }
    while(a[pt].vis) ++pt;
    a[pt].vis = 1;
    for(int i = 1; i <= n; ++i) {
        if(i == pt) continue;
        if(!a[i].vis) {
            a[i].vis = 1;
            q.push_back((Line){a[i].x - a[pt].x, a[i].y - a[pt].y});
            dfs(pt + 1);
            q.pop_back();
            a[i].vis = 0;
        }
    }
    a[pt].vis = 0;
    return ;
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i].x >> a[i].y;
    dfs(1);
    cout << ans;
    return 0;
}