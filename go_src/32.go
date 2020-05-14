func search(nums []int, target int) int {
	l, r := 0, len(nums) - 1
	for l < r {
		mid := (l + r) >> 1
		if nums[l] <= nums[mid] && target >= nums[l] && target <= nums[mid] {
			r = mid
		} else if nums[l] > nums[mid] && (target >= nums[l] || target <= nums[mid]) {
			r = mid
		} else {
			l = mid + 1
		}
	}
	if l == r && nums[l] == target {
		return l
	} else {
		return -1
	}
}
