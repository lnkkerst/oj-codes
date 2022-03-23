#include<cstdio>
using namespace std;
int a[100001];
int qsort(int l,int r){
	int n=l,m=r,x=a[(l+r)/2],t;
	for (;n<m;){
		for (;a[n]<x;n++);
		for (;a[m]>x;m--);
		if (n<=m){
			t=a[n];
			a[n]=a[m];
			a[m]=t;
			n++;
			m--;
		}
	}
	if (l<m) qsort(l,m);
	if (r>n) qsort(n,r);
}
int main(){
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	qsort(1,n);
	for (int i=1;i<n;i++) printf("%d ",a[i]);
	printf("%d\n",a[n]);
	return 0;
}