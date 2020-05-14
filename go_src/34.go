func helper(nums []int, target int, left bool) int {
	lo, hi := 0, len(nums)
	for lo < hi {
		mid := (lo + hi) >> 1
		if nums[mid] > target || (left && nums[mid] == target) {
			hi = mid
		} else {
			lo = mid + 1
		}
	}
	return lo
}

func searchRange(nums []int, target int) []int {
	result := []int{-1, -1}

	l := helper(nums, target, true)

	if l == len(nums) || nums[l] != target {
		return result
	}

	result[0] = l
	result[1] = helper(nums, target, false) - 1

	return result
}
