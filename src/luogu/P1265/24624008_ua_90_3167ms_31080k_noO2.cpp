#include <bits/stdc++.h>

using namespace std;

struct Node {
    int x, y;
    bool ind;
    double dis;
} nodes[5010];

int n, m;

double calc(int a, int b) {
    return sqrt((double)(nodes[a].x - nodes[b].x) * (nodes[a].x - nodes[b].x) + (double)(nodes[a].y - nodes[b].y) * (nodes[a].y - nodes[b].y));
}

double prim(int s) {
    set <pair <double, int> > heap;
    double ret = 0;
    for(int i = 1; i <= n; ++i) nodes[i].dis = 0x3f3f3f3f;
    nodes[s].dis = 0;
    nodes[s].ind = 1;
    for(int i = 1; i <= n; ++i) heap.insert(make_pair(nodes[i].dis, i));
    while(heap.size() > 0) {
        double d = heap.begin()->first;
        int u = heap.begin()->second;
        heap.erase(heap.begin());
        if(d > nodes[u].dis) continue;
        nodes[u].ind = 1;
        for(int i = 1; i <= n; ++i) {
            if(i == u) continue;
            double ca = calc(i, u);
            if(!nodes[i].ind && nodes[i].dis > ca) {
                nodes[i].dis = ca;
                heap.insert(make_pair(ca, i));
            }
        }
    }
    for(int i = 1; i <= n; ++i) ret += nodes[i].dis;
    return ret;
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> nodes[i].x >> nodes[i].y;
    printf("%.2lf", prim(1));
    return 0;
}