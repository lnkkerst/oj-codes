#include <bits/stdc++.h>
using namespace std;

struct Node {
    int l, r;
    mutable bool v;
    Node(int _l, int _r = -1, bool _v = 0) {
        l = _l, r = _r, v = _v;
    }
    bool operator<(const Node& b) const {
        return l < b.l;
    }
} ;

set<Node > nodes;

#define IT set<Node >::iterator

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

IT split(int pos) {
    IT it = nodes.lower_bound(Node(pos));
    if(it != nodes.end() && it->l == pos) return it;
    --it;
    int _l = it->l, _r = it->r, _v = it->v;
    nodes.erase(it), nodes.insert(Node(_l, pos - 1, _v));
    return nodes.insert(Node(pos, _r, _v)).first;
}

void assign(int l, int r, bool _v) {
    IT itl = split(r + 1), itr = split(l);
    nodes.erase(itl, itr), nodes.insert(Node(l, r, _v));
}

int sum(int l, int r) {
    IT itr = split(r + 1), itl = split(l);
    int ret = 0;
    for (; itl != itr; ++itl)
        ret += itl->v ? itl->r - itl->l + 1 : 0;
    return ret;
}

void rev(int l, int r) {
    IT itl = split(l), itr = split(r + 1);
    while(itl != itr) itl->v ^= 1, ++itl;
}

int count(int l, int r) {
    IT itl = split(r + 1), itr = split(l);
    int ret = 0, tmp = 0;
    while(itl != itr) {
        if(!itl->v) ret = max(ret, tmp), tmp = 0;
        else tmp += itl->r - itl->l + 1;
        ++itl;
    }
    return max(ret, tmp);
}


int n, m;

int main() {
    n = read(), m = read();
    for(int i = 0; i < n; ++i) nodes.insert(Node(i, i, read()));
    nodes.insert(Node(n, n, 0));
    for(int i = 1; i <= m; ++i) {
        int opt = read(), a = read(), b = read();
        if(opt == 0) assign(a, b, 0);
        else if(opt == 1) assign(a, b, 1);
        else if(opt == 2) rev(a, b);
        else if(opt == 3) print(sum(a, b)), putchar('\n');
        else print(count(a, b)), putchar('\n');
    }
    return 0;
}