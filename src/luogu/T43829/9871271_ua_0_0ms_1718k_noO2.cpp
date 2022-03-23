#include<cstdio>
#include<cmath>
using namespace std;
int a[100010],t=0;
void opt1(){
	int n,m;
	scanf("%ld%ld",&n,&m);
	for (int i=0;i<n;i++){
		a[t]=m;t++;
	}
}
void opt2(){
	int n;
	scanf("%ld",&n);
	for (int i=0;i<t;i++){
		a[i]=a[i+n];
	}
	t=t-n;
}
void opt3(){
	int l,r,x,c,m;
	scanf("%ld%ld%ld%ld",&l,&r,&x,&c);
	m=r-l+1;
	m=pow(m,x);
	m%=c;
	for (int i=l-1;i<r;i++){
		a[i]=m;
	}
}
void opt4(){
	int l,r,max=0;
	scanf("%ld%ld",&l,&r);
	for (int i=l-1;i<r;i++) if (a[i]>max) max=a[i];
	a[l-1]=max;
	for (int i=l;i<t;i++){
		a[i]=a[i+r-l];
	}
	t=t-(r-l);
	printf("%d\n",max);
}
void opt5(){
	int l,r;
	scanf("%ld%ld",&l,&r);
	for (int i=l-1;i<r;i++){
		a[i]=sqrt(a[i]);
	}
}
int main(){
	int m,n;
	scanf("%ld",&m);
	for (int i=0;i<m;i++){
		scanf("%ld",&n);
		if (n==1) opt1();
		else if (n==2) opt2();
		else if (n==3) opt3();
		else if (n==4) opt4();
		else if (n==5) opt5();
	}
	for (int i=0;i<t;i++) printf("%ld",a[i]);
	return 0;
}