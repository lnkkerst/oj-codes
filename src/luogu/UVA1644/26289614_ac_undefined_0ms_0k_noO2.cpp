// // // // #include <cstdio>
// // // // #include <iostream>
// // // // #include <cstring>
// // // // #include <algorithm>
// // // // #include <vector>
// // // // #include <queue>
// // // // using namespace std;

// // // // struct Node {
// // // //     int dep, du;
// // // //     bool vis, end;
// // // //     Node *fa;
// // // //     vector<struct Edge > e;
// // // //     vector<Node* > to;
// // // // } nodes[100010];

// // // // struct Edge {
// // // //     Node *from, *to;
// // // // } ;

// // // // // struct cmp {
// // // // //     bool operator()(Node a, Node b) {
// // // // //         return a.dep > b.dep;
// // // // //     }
// // // // // } ;

// // // // int n;
// // // // vector<Node* > le;

// // // // int read() {
// // // // 	int ret, f = 1;
// // // // 	char ch;
// // // // 	while(!isdigit(ch = getchar())) (ch == '-') && (f = -1);
// // // // 	for(ret = ch - '0'; isdigit(ch = getchar()); ret *= 10, ret += ch - '0');
// // // // 	return ret * f;
// // // // }

// // // // bool cmp(Node a, Node b) {
// // // //     return a.dep < b.dep;
// // // // }

// // // // void print(int x) {
// // // // 	if(x < 0) putchar('-'), x = -x;
// // // // 	if(x > 9) print(x / 10);
// // // // 	putchar(x % 10 + '0');
// // // // }

// // // // void addedge(int u, int v) {
// // // //     nodes[u].e.push_back((Edge){&nodes[u], &nodes[v]});
// // // //     ++nodes[u].du;
// // // //     nodes[v].fa = &nodes[u];
// // // // }

// // // // void dfs(Node *fa) {
// // // //     if(fa->e.empty()) fa->end = 1, le.push_back(fa);
// // // //     for(vector<Edge >::iterator i = fa->e.begin(); i !=fa->e.end(); ++i) {
// // // //         i->to->dep = fa->dep + 1;
// // // //         dfs(i->to);
// // // //     }
// // // // }

// // // // void init(Node *fa) {
// // // //     dfs(fa);
    
// // // // }

// // // // int main() {
// // // //     n = read();
// // // //     for(int i = 2; i <= n; ++i) addedge(read(), i);
    
// // // //     // priority_queue<Node , vector<Node > , cmp> h1;
// // // //     int now = 1;
// // // //     while(233) {
// // // //         make_heap(le.begin(), le.end(), cmp);
// // // //         nodes[now].dep = 0, init(&nodes[now]);
// // // //     }
// // // //     // for(int i = 1; i <= n; ++i) printf("%d %d\n", nodes[i].dep, nodes[i].end);
// // // //     return 0;
// // // // }

// // // #include <cstdio>
// // // #include <cstring>
// // // #include <algorithm>
// // // #include <cmath>
// // // #include <map>
// // // using namespace std;
// // // const int MOD = 233666765;

// // // struct Node {
// // //     double x, y;
// // // } nodes[10010];

// // // map<int, double > s;
// // // int n, k;

// // // int read() {
// // // 	int ret, f = 1;
// // // 	char ch;
// // // 	while(!isdigit(ch = getchar())) (ch == '-') && (f = -1);
// // // 	for(ret = ch - '0'; isdigit(ch = getchar()); ret *= 10, ret += ch - '0');
// // // 	return ret * f;
// // // }

// // // void print(int x) {
// // // 	if(x < 0) putchar('-'), x = -x;
// // // 	if(x > 9) print(x / 10);
// // // 	putchar(x % 10 + '0');
// // // }

// // // double calc_dis(Node a, Node b) {
// // //     return (sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2)));
// // // }

// // // double calc_s(Node a, Node b, Node c) {
// // //     double da = calc_dis(c, b), db = calc_dis(a, c), dc = calc_dis(b, a);
// // //     double p = (da + db + dc) / 2.0;
// // //     return (sqrt(p * (p - da) * (p - db) * (p - dc)));
// // // }

// // // int calc_hash(int a, int b, int c) {
// // //     return (a * 100 + b * 10 + c) % MOD;
// // // }

// // // int main() {
// // //     n = read(), k = read();
// // //     for(int i = 1; i <= n; ++i) scanf("%lf%lf", &nodes[i].x, &nodes[i].y);
// // //     double S = 0;
// // //     for(int i = 2; i <= n - 1; ++i) S += calc_s(nodes[1], nodes[i], nodes[i + 1]);

// // // }

// // #include <bits/stdc++.h>
// // using namespace std;
// // #define int long long
// // const int maxn=2505;
// // struct node{double x,y;
// // double operator *(const node&b)const
// // {
// // 	return 1.0*x*b.y-1.0*b.x*y;
// // }
// // node operator -(const node&b)const
// // {
// // 	return (node){x-b.x,y-b.y};
// // }
// // }d[maxn<<1];
// // int mmax(int x,int y)
// // {
// // 	return x>y?x:y;
// // }
// // double myabs(double x)
// // {
// // 	return x>0?x:-x;
// // }
// // int n,k,c[2505][2505];
// // double tot[maxn];
// // double mx;
// // signed main()
// // {
// // 	scanf("%lld%lld",&n,&k);
// // 	for(int i=1;i<=n;++i)
// // 	{
// // 		scanf("%lf%lf",&d[i].x,&d[i].y);
// // 	}
// // 	for(int i=n+1;i<=(n<<1);++i)d[i]=d[i-n];
// // 	mx=0;
// // 	for(int i=3;i<=n;++i)
// // 	{
// // 		mx+=(d[i]-d[1])*(d[i-1]-d[1]);
// // 	}
// // 	if(mx<0)mx=-mx;
// // 	for(int i=1;i<=2*n;++i)
// // 	{
// // 		double now=0;int lim=mmax(0,i-n);
// // 		for(int j=i-2;j>=1;--j)
// // 		{
// // 			now+=(d[j+1]-d[i])*(d[j]-d[i]);
// // 			if(i>n&&j>n)continue;
// // 			tot[i-j-1]+=myabs(now);
// // 		}
// // 	}
// // 	double re=0.0;
// // 	for(int i=1;i<=n-k;++i)
// // 	{
// // 		double gg=1.0;
// // 		for(int j=k-1;j>=0;--j)
// // 		{
// // 			gg=1.0*gg/(n-j)*(n-i-j);
// // 		}
// // 		gg=1.0*gg*(k-1)*k;
// // 		gg=1.0*gg/(n-i-1)/(n-i);
// // 		//gg=1.0*c[n-i-2][n-i-k]/c[n][n-k];
// // 		re+=1.0*gg*tot[i];
// // 	}
// // 	double ans=0.0+mx-re;
// // 	ans=ans*0.5;
// // 	printf("%.10f\n",ans);
// //   return 0;
// // }

// #include <cstdio>

// int max(int x,int max(int y,int z)) {
//     return x;
// }

// int main() {
//     return 0;
// }
#include <cstdio>

bool pd(int a){
    if(a == 1) return 0;
    if(a == 2 || a == 3) return 1;
    if(a % 6 != 1 && a % 6 != 5) return 0;
    for(int i = 5; i * i <= a; i += 6)
        if(a % i == 0 || a % (i + 2) == 0) return 0;
    return 1;
}

int main() {
    int n;
    while(233) {
        scanf("%d", &n);
        if(!n) return 0;
        if(pd(n)) puts("0");
        else {
            int nex, last, i = n;
            while(i < 1299709)
                if(pd(i)) {
                    nex = i;
                    break;
                }
                else ++i;
            i = n;
            while(i > 2) {
                if(pd(i)) {
                    last = i;
                    break;
                }
                else --i;
            }
            printf("%d\n", nex - last);
        }
    }
    return 0;
}