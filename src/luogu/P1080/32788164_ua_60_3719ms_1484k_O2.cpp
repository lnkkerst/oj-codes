#include <iostream>
#include <algorithm>
using namespace std;

int cmp(const string &a, const string &b);
string mul(const string &a, const string &b);

struct Node {
	string l, r;
	bool operator<(const Node &b) const {
		return cmp(mul(this->l, this->r), mul(b.l, b.r)) == -1;
	}
} a[10001];

int n;

string sum(const string &a, const string &b) {
	string na = string(a.rbegin(), a.rend());
	string nb = string(b.rbegin(), b.rend());
	int last = 0;
	string ret;
	if(na.size() < nb.size()) swap(na, nb);
	for(int i = 0; i < (int)nb.size(); ++i)
		ret.push_back((na[i] + nb[i] - 96 + last) % 10 + 48),
		last = (na[i] + nb[i] - 96 + last) / 10;
	for(int i = (int)nb.size(); i < (int)na.size(); ++i)
		ret.push_back((na[i] - 48 + last) % 10 + 48),
		last = (na[i] - 48 + last) / 10;
	if(last) ret.push_back(last + 48);
	return string(ret.rbegin(), ret.rend());
}

string sub(const string &a, const string &b) {
	string na = string(a.rbegin(), a.rend());
	string nb = string(b.rbegin(), b.rend());
	string ret;
	for(int i = 0; i < (int)nb.size(); ++i)
		(na[i] < nb[i]) && (na[i] += 10, --na[i + 1]),
		ret.push_back(na[i] - nb[i] + 48);
	for(int i = (int)nb.size(); i < (int)na.size(); ++i)
		(na[i] < 0) && (na[i] += 10, --na[i + 1]),
		ret.push_back(na[i]);
	while((int)ret.size() > 1 && ret.back() == 48)
		ret.pop_back();
	return string(ret.rbegin(), ret.rend());
}

string mul(const string &a, const string &b) {
	string na = string(a.rbegin(), a.rend());
	string nb = string(b.rbegin(), b.rend());
	string ret;
	ret.resize(na.size() + nb.size() + 1);
	for(int i = 0; i < (int)na.size(); ++i)
		for(int j = 0; j < (int)nb.size(); ++j)
			ret[i + j] += (na[i] - 48) * (nb[j] - 48);
	for(int i = 0; i < (int)ret.size(); ++i)
		ret[i + 1] += ret[i] / 10, ret[i] %= 10;
	while(ret.size() > 1 && !ret.back()) ret.pop_back();
	for(int i = 0; i < (int)ret.size(); ++i) ret[i] += 48;
	return string(ret.rbegin(), ret.rend());
}

int cmp(const string &a, const string &b) {
	if(a.size() > b.size()) return 1;
	if(a.size() < b.size()) return -1;
	for(int i = 0; i < (int)a.size(); ++i) {
		if(a[i] > b[i]) return 1;
		else if(a[i] < b[i]) return -1;
	}
	return 0;
}

string div(string a, string b) {
	string ret("0"), base(b), ab("1");
	while(cmp(a, base) >= 0)
		base.push_back('0'), ab.push_back('0');
	base.pop_back(), ab.pop_back();
	while(cmp(a, b) >= 0) {
		while(cmp(a, base) >= 0)
			a = sub(a, base), ret = sum(ret, ab);
		while(cmp(base, a) > 0)
			base.pop_back(), ab.pop_back();
	}
	return ret;
}

int main() {
	cin >> n >> a[0].l >> a[0].r;
	for(int i = 1; i <= n; ++i)
		cin >> a[i].l >> a[i].r;
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