func nextPermutation(nums []int)  {
	n := len(nums)
	if n < 2 {
		return
	}
	i, j, k := n - 2, n - 1, n - 1
	for i >= 0 && nums[i] >= nums[j] {
		i--
		j--
	}
	if i >= 0 {
		for nums[k] <= nums[i] {
			k--
		}
		nums[i], nums[k] = nums[k], nums[i]
	}

	for n--; j < n; j, n = j + 1, n - 1 {
		nums[j], nums[n] = nums[n], nums[j]
	}
}
