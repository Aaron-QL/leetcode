func removeDuplicates(nums []int) int {
    i, n := 0, len(nums)
    if n < 2 {
        return n
    }
    for j := 1; j < n; j++ {
        if nums[i] != nums[j] {
            i++
            nums[i] = nums[j]
        }
    }

    return i + 1
}
