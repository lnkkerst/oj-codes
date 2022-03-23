#include<cstdio>
#include<cmath>
using namespace std;
bool ss(int x){
	for (int i=2;i<=sqrt(x);i++)
		if (x%i==0) return 0;
	return 1;
}
bool hws(int x){
	int t=x,tmp=0;
	while (x!=0){
		tmp*=10;
		tmp+=x%10;
		x/=10;
	}
	if (tmp==t) return 1;
	else return 0;
}
int main(){
	int a,b;
	scanf("%ld%ld",&a,&b);
	for (int i=a;i<=b;i++)
		if (hws(i)==1)
			if (ss(i)==1) printf("%d\n",i);
	return 0;
}