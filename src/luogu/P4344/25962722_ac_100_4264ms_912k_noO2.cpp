#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#define IT set<Node >::iterator
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
    IT itr = split(r + 1), itl = split(l);
    nodes.erase(itl, itr), nodes.insert(Node(l, r, _v));
}

int count(int l, int r) {
    IT itr = split(r + 1), itl = split(l);
    int ret = 0, tmp = 0;
    while(itl != itr) {
        if(!itl->v) tmp += itl->r - itl->l + 1;
        else if(tmp) ret = max(ret, tmp), tmp = 0; 
        ++itl;
    }
    return max(ret, tmp);
}

void fix(int l, int r, int _l, int _r) {
	IT itr = split(r + 1), itl = split(l), it = itl;
	int sum = 0;
	while(itl != itr) {
		if(itl->v) sum += itl->r - itl->l + 1;
		++itl;
	}
	nodes.erase(it, itr), nodes.insert(Node(l, r, 0));
	if(!sum) return ;
	itr = split(_r + 1), itl = split(_l), it = itl;
	if(sum >= _r - _l + 1) {
		nodes.erase(itl, itr), nodes.insert(Node(_l, _r, 1));
		return ;
	}
	while(itl != itr) {
		if(!itl->v) {
			sum -= itl->r - itl->l + 1;
			if(sum < 0) {
				assign(itl->l, itl->r + sum, 1);
				break;
			}
			else itl->v = 1;
		}
		++itl;
	}
}

int n, m;

int main() {
    n = read(), m = read();
    nodes.insert(Node(1, n, 1));
    for(int i = 1; i <= m; ++i) {
        int opt = read(), a = read(), b = read(), a1, b1;
        if(opt == 0) assign(a, b, 0);
        else if(opt == 1) a1 = read(), b1 = read(), fix(a, b, a1, b1);
        else if(opt == 2) print(count(a, b)), putchar('\n');
    }
    return 0;
}