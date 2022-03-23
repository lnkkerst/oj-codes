#include<cstdio>
using namespace std;
int main(){
	int n,k,s=0,tmp1=0,tmp2;
	scanf("%ld%ld",&n,&k);
	while(n>0){
		s=s+n;
		tmp2=n+tmp1;
		n=tmp2/k;
		tmp1=tmp2%k;
	}
	printf("%ld",s);
	return 0;
}