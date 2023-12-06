package main

import (
	"fmt"
)

func query(pos int, n int, k int, mp map[int]int) int {
	if val, ok := mp[pos]; ok {
		return val
	}
	if pos == 0 || pos == n+1 {
		return 1
	}
	if pos <= k {
		return 1
	}
	return 0
}

func main() {
	var t, x, y int
	fmt.Scan(&t)
	for qwq := 1; qwq <= t; qwq++ {
		fmt.Printf("Case %d:\n", qwq)
		mp := make(map[int]int)

		var n, k, q int
		fmt.Scan(&n, &k, &q)
		ans := 1

		for q > 0 {
			fmt.Scan(&x, &y)

			cx := query(x-1, n, k, mp) + query(x+1, n, k, mp)
			if cx == 0 {
				ans--
			} else if cx == 2 {
				ans++
			}
			mp[x] = 0

			cy := query(y-1, n, k, mp) + query(y+1, n, k, mp)
			if cy == 0 {
				ans++
			} else if cy == 2 {
				ans--
			}
			mp[y] = 1

			fmt.Println(ans)
			q--
		}
	}
}
