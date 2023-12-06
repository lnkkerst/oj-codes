package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scanln(&n)

	totalCost := 0.0

	for i := 0; i < n; i++ {
		var price, discount int
		fmt.Scanln(&price, &discount)
		totalCost += float64(price) * float64(discount) / 10
	}

	fmt.Printf("%.2f\n", totalCost)
}
