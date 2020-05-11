package main

import (
	"fmt"
	"math"
	"sort"
)

func main() {
	fmt.Println(threeSumClosest([]int{1, 1, 1, 0}, -100))
}

const INT_MAX = int(^uint(0) >> 1)

func threeSumClosest(nums []int, target int) int {
	n := len(nums)
	if n < 3 {
		return 0
	}
	minDiff := INT_MAX
	sum := nums[0] + nums[1] + nums[2]
	sort.Ints(nums)
	for i := 0; i < n - 2; i++ {
		j, k := i+1, n-1
		for j < k {
			sumT := nums[i] + nums[j] + nums[k]
			if abs := int(math.Abs(float64(sumT - target))); abs < minDiff {
				minDiff = abs
				sum = sumT
			}
			if sumT < target {
				for j++; j < k && nums[j] == nums[j-1]; j++ {}
			} else if sumT > target {
				for k--; j < k && nums[k] == nums[k+1]; k-- {}
			} else {
				return target
			}
		}
	}
	return sum
}
