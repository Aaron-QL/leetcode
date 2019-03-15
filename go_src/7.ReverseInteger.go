package main

import "fmt"

func reverse(x int) int {
	minInt32, maxInt32 := -2147483648, 2147483647
	ans := 0
	for ;x != 0; x /= 10 {
		ans = ans * 10 + x % 10
		if ans > maxInt32 || ans < minInt32 {
			return 0
		}
	}

	return ans
}



func main() {
	fmt.Println(reverse(-1112))
}