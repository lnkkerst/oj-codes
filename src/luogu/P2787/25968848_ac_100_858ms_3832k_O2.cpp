#include <cstdio>
#include <iostream>
#include <cctype>
#include <cstring>
#include <set>
#define IT set<Node >::iterator
using namespace std;

struct Node {
    int l, r;
    mutable char v;
    Node(int _l, int _r = -1, char _v = 0) { l = _l, r = _r, v = _v; }
    bool operator<(const Node& b) const { return l < b.l; }
} ;
set<Node > nodes;
IT split(int pos) {
    IT it = nodes.lower_bound(Node(pos));
    if(it != nodes.end() && it->l == pos) return it;
    --it;
    int _l = it->l, _r = it->r; char _v = it->v;
    nodes.erase(it), nodes.insert(Node(_l, pos - 1, _v));
    return nodes.insert(Node(pos, _r, _v)).first;
}
void assign(int l, int r, char _v) {
    IT itr = split(r + 1), itl = split(l);
    nodes.erase(itl, itr), nodes.insert(Node(l, r, _v));
}
int count(int l, int r, char _v) {
	IT itr = split(r + 1), itl = split(l); int ret = 0;
	for(; itl != itr; ++itl) if(itl->v == _v) ret += itl->r - itl->l + 1;
	return ret;
}
void sort_odt(int l, int r) {
	IT itr = split(r + 1), itl = split(l), it = itl; int arr[27] = {0};
	while(itl != itr) arr[itl->v - 'A' + 1] += itl->r - itl->l + 1, ++itl;
	nodes.erase(it, itr);
	for(int i = 1; i <= 26; ++i)
		if(arr[i]) nodes.insert(Node(l, l + arr[i] - 1, i + 'A' - 1)), l += arr[i];
}
int n, m, cnt = 1, opt, a, b;
string s;
int main() {
    cin >> n >> m >> s;
    char last = toupper(s[0]);
	for(int i = 1; i < n; ++i) {
		s[i] = toupper(s[i]);
		if(s[i] == last) ++cnt;
		else nodes.insert(Node(i - cnt + 1, i, last)), last = s[i], cnt = 1;
	}    
	nodes.insert(Node(n + 1 - cnt, n, last));
	for(int i = 1; i <= m; ++i) {
		cin >> opt >> a >> b;
		if(opt == 1) cin >> s, cout << count(a, b, toupper(s[0])) << endl;
		else if(opt == 2) cin >> s, assign(a, b, toupper(s[0]));
		else sort_odt(a, b);
	}
	return 0;
}