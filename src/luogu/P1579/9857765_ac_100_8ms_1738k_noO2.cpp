#include<cstdio>
#include<cmath>
using namespace std;
int pd(int x){
	for (int i=2;i<=sqrt(x);i++){
		if (x%i==0) return 0;
	}
	return 1;
}
int main(){
	int n;
	scanf("%ld",&n);
	for (int i=2;i<=n-4;i++)
		for (int j=2;j<=n-4;j++){
			int k=n-i-j;
			if (pd(i)+pd(j)+pd(k)==3){
				printf("%ld %ld %ld",i,j,k);
				return 0;
			}
		}
}