#include <iostream>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <vector>
using namespace std;

int cmp(string a, string b);
string mul(string a, string b);

struct Node {
	string l, r;
	bool operator<(const Node &b) const {
		return cmp(mul(this->l, this->r), mul(b.l, b.r)) == -1;
	}
} a[10001];

int n;

int readint() {
	int ret, fl = 1;
	char ch;
	while(!isdigit(ch = getchar()))
		(ch == '-') && (fl = -1);
	ret = ch - '0';
	while(isdigit(ch = getchar()))
		ret *= 10, ret += ch - '0';
	return ret * fl;
}

void printint(int x) {
	if(x < 0) putchar('-'), x = -x;
	if(x > 9) printint(x / 10);
	putchar(x % 10 + '0');
}

string sum(string a, string b) {
	string ret;
	vector<int > na, nb;
	int la = a.size(), lb = b.size();
	int lmax = max(la, lb);
	for(int i = 0; i <= lmax; ++i) na.push_back(0), nb.push_back(0);
	for(int i = 0; i < la; ++i) na[la - i - 1] = a[i] - '0';
	for(int i = 0; i < lb; ++i) nb[lb - i - 1] = b[i] - '0';
	for(int i = 0; i < lmax; ++i) na[i] += nb[i], na[i + 1] += na[i] / 10, na[i] = na[i] % 10;
	if(na[lmax]) ++lmax;
	for(int i = lmax - 1; i >= 0; --i) ret += na[i] + '0';
	return ret;
}

string sub(string a, string b) {
	string ret;
	vector<int > na, nb;
	int la = a.size(), lb = b.size();
	int lmax = max(la, lb);
	for(int i = 0; i <= lmax; ++i) na.push_back(0), nb.push_back(0);
	for(int i = 0; i < la; ++i) na[la - i - 1] = a[i] - '0';
	for(int i = 0; i < lb; ++i) nb[lb - i - 1] = b[i] - '0';
	for(int i = 0; i < lmax; ++i) {na[i] -= nb[i]; if(na[i] < 0) na[i] += 10, --na[i + 1];}
	while(!na[lmax] && lmax > 0) --lmax;
	++lmax;
	for(int i = lmax - 1; i >= 0; --i) ret += na[i] + '0';
	return ret;
}

string mul(string a, string b) {
	string ret;
	vector<int > na, nb, nc;
	int la = a.size(), lb = b.size();
	for(int i = 0; i < (la + lb); ++i) nc.push_back(0);
	for(int i = 0; i < la; ++i) na.push_back(a[la - i - 1] - '0');
	for(int i = 0; i < lb; ++i) nb.push_back(b[lb - i - 1] - '0');
	for(int i = 0; i < la; ++i)
		for(int j = 0; j < lb; ++j)
			nc[i + j] += na[i] * nb[j];
	for(int i = 0; i < la + lb; ++i) nc[i + 1] += nc[i] / 10, nc[i] %= 10;
	int retlen = la + lb - 1;
	while(!nc[retlen]) --retlen;
	for(int i = retlen; i >= 0; i--) ret += nc[i] + '0';
	return ret;
}
int cmp(string a, string b) {
	if(a == b) return 0;
	int la = a.length(), lb = b.length();
	if(la != lb) return la > lb ? 1 : -1;
	for(int i = 0; i <= la; ++i) 
		if(a[i] < b[i]) return -1;
	return 1;
}
string div(string a, string b) {
	string ret = "0", base = b, ab = "1";
	while(cmp(a, mul(base, "10")) >= 0) base = mul(base, "10"), ab = mul(ab, "10");
	while(cmp(a, b) >= 0) {
		while(cmp(a, base) >= 0) a = sub(a, base), ret = sum(ret, ab);
		base = b, ab = "1";
		while(cmp(a, mul(base, "10")) >= 0) base = mul(base, "10"), ab = mul(ab, "10");
	}
	return ret;
}

signed main() {
	cin >> n >> a[0].l >> a[0].r;
	for(int i = 1; i <= n; ++i) cin >> a[i].l >> a[i].r;
	sort(a + 1, a + n + 1);
	string ans = "0", sm = a[0].l;
	for(int i = 1; i <= n; ++i) {
		if(cmp(div(sm, a[i].r), ans) == 1)
			ans = div(sm, a[i].r);
		sm = mul(sm, a[i].l);
	}
	cout << ans;
	return 0;
}