#include <iostream>

int pd(int x){
	int ans = 0;
	while (x != 0) {
		if (x%10 == 2) ans ++;
		x = x / 10;
	}
	return ans;
}

int main() {
	int l, r, ans=0;
	std::cin >> l >> r;
	for (int i = l; i <= r; i++) ans += pd(i);
	std::cout << ans;
	return 0;
}