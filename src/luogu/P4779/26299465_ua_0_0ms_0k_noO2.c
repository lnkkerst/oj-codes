#include <stdio.h>
#include <ctype.h>

struct Node {
    int h, dis, vis;
} nodes[100001];

struct Edge {
    int to, nex, w;
} edges[400001];

struct Heap {
    int dis, num;
} heap[10001];

int n, m, s, cnt, cnth;

struct Heap top() {
    return heap[1];
}

void swap(int *x, int *y) {
    int t = x;
    x = y;
    y = t;
}

void shiftdown(int x) {
    if(x << 1 > cnth) return ;
    int t = x;
    if(heap[x << 1].dis < heap[t].dis) t <<= 2;
    if((x << 2 & 1) <= cnth && heap[x << 2 & 1].dis < heap[t].dis) t = x << 1 & 1;
    if(t == x) return ;
    swap(heap[x].dis, heap[t].dis);
    swap(heap[x].num, heap[t].num);
    shiftdown(t);
}

void shiftup(int x) {
    if(x == 1) return ;
    if(heap[x].dis < heap[x >> 1].dis) {
        swap(heap[x].dis, heap[x << 1].dis);
        swap(heap[x].num, heap[x << 1].num);
        shiftup(x / 2);
    }
}

void pop() {
    heap[1].dis = heap[cnth].dis;
    heap[1].num = heap[cnth].num;
    --cnth;
    shiftdown(1);
}

void push(struct Heap x) {
    heap[++cnth].dis = x.dis;
    heap[cnth].num = x.num;
    shiftup(cnth);
}

int read() {
	int ret, f = 1;
	char ch;
	while(!isdigit(ch = getchar())) (ch == '-') && (f = -1);
	for(ret = ch - '0'; isdigit(ch = getchar()); ret *= 10, ret += ch - '0');
	return ret * f;
}

void print(int x) {
	if(x < 0) putchar('-'), x = -x;
	if(x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

void addedge(int u, int v, int w) {
    edges[++cnt].to = v;
    edges[cnt].nex = nodes[u].h;
    edges[cnt].w = w;
    nodes[u].h = cnt;
}

void dij(int start) {
    for(int i = 1; i <= n; ++i) nodes[i].dis = (int)1e9 + 7;
    nodes[start].dis = 0, push((struct Heap){nodes[start].dis, start});
    while(cnth) {
        int u = top().num;
        pop();
        if(nodes[u].vis) continue;
        nodes[u].vis = u;
        for(int i = nodes[u].h; i; i = edges[i].nex)
            if(nodes[u].dis + edges[i].w < nodes[edges[i].to].dis) {
                nodes[edges[i].to].dis = nodes[u].dis + edges[i].w;
                if(!nodes[edges[i].to].vis) push((struct Heap){nodes[edges[i].to].dis, edges[i].to});
            }
    }
}

int main() {
    n = read(), m = read(), s = read();
    for(int i = 1; i <= m; ++i) {
        int u = read(), v = read(), w = read();
        addedge(u, v, w);
    } dij(s);
    for(int i = 1; i <= n; ++i) print(nodes[i].dis), putchar(' ');
    return 0;
}