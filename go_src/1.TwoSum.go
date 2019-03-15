package leetcode

func twoSum1(nums []int, target int) []int {
	for k1, v1 := range nums {
		for k2, v2 := range nums {
			if k1 != k2 && v1 + v2 == target {
				return []int {k1, k2}
			}
		}
	}
	return []int{};
}

func twoSum2(nums []int, target int) []int {
	m := make(map[int]int)
	for i, v := range nums {
		if j, ok := m[target - v]; ok {
			return []int{i, j}
		}
		m[v] = i;
	}
	return []int{}
}