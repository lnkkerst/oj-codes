package main

import (
	"fmt"
)

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func solve() {
	var n int
	fmt.Scanln(&n)

	a := make([][]int, n)
	for i := range a {
		a[i] = make([]int, n+1)
	}

	for i := 1; i <= n-1; i++ {
		for j := i + 1; j <= n; j++ {
			fmt.Scan(&a[i][j])
		}
	}

	dp := make([]int, n+1)
	for i := range dp {
		dp[i] = 1e9
	}
	dp[1] = 0

	for i := 1; i <= n; i++ {
		for j := 1; j < i; j++ {
			dp[i] = min(dp[i], dp[j]+a[j][i])
		}
	}

	fmt.Println(dp[n])
}

func main() {
	var t int = 1
	for t > 0 {
		solve()
		t--
	}
}
