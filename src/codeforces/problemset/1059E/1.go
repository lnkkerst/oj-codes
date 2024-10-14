package main

import (
	"fmt"
)

const (
	maxn = 100005
	lg   = 20
	inf  = 1e18
)

type Tree struct {
	n    int
	L    int
	S    int64
	w    []int64
	down [][]int
	sum  []int64
	up   []int
	h    []int
	p    [][]int
	path []int
}

func NewTree(n, L int, S int64) *Tree {
	w := make([]int64, n)
	down := make([][]int, n)
	sum := make([]int64, n)
	up := make([]int, n)
	h := make([]int, n)
	p := make([][]int, n)
	for i := range p {
		p[i] = make([]int, lg)
		for j := range p[i] {
			p[i][j] = -1
		}
	}
	path := make([]int, n)

	return &Tree{n, L, S, w, down, sum, up, h, p, path}
}

func (t *Tree) getSum(v int) int64 {
	if v == -1 {
		return 0
	}
	return t.sum[v]
}

func (t *Tree) preprocess(v int, pr int) {
	t.sum[v] = t.getSum(pr) + t.w[v]
	t.p[v][0] = pr
	if pr == -1 {
		t.h[v] = 0
	} else {
		t.h[v] = 1 + t.h[pr]
	}
	t.up[v] = v

	for i := 1; i < lg; i++ {
		if t.p[v][i-1] == -1 {
			t.p[v][i] = -1
		} else {
			t.p[v][i] = t.p[t.p[v][i-1]][i-1]
		}
	}

	dist := t.L - 1
	for i := lg - 1; i >= 0; i-- {
		if t.p[t.up[v]][i] == -1 || (1<<i) > dist {
			continue
		}
		if t.getSum(v)-t.getSum(t.p[t.up[v]][i])+t.w[t.p[t.up[v]][i]] <= t.S {
			dist -= 1 << i
			t.up[v] = t.p[t.up[v]][i]
		}
	}

	for _, u := range t.down[v] {
		t.preprocess(u, v)
	}
}

func (t *Tree) solve(v int) int {
	ans := 0
	best := -1

	for _, u := range t.down[v] {
		ans += t.solve(u)
		if t.path[u] == u {
			continue
		}
		if best == -1 || t.h[best] > t.h[t.path[u]] {
			best = t.path[u]
		}
	}

	if best == -1 {
		best = t.up[v]
		ans++
	}
	t.path[v] = best
	return ans
}

func main() {
	var n, L int
	var S int64
	fmt.Scan(&n, &L, &S)

	tree := NewTree(n, L, S)

	for i := 0; i < n; i++ {
		fmt.Scan(&tree.w[i])
		if tree.w[i] > S {
			fmt.Println("-1")
			return
		}
	}

	for i := 1; i < n; i++ {
		var j int
		fmt.Scan(&j)
		tree.down[j-1] = append(tree.down[j-1], i) // Convert to zero-based index
	}

	tree.preprocess(0, -1)
	fmt.Println(tree.solve(0))
}
