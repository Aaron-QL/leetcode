func fourSum(nums []int, target int) [][]int {
    sort.Ints(nums)
    result := [][]int{}
    n := len(nums)
    for i := 0; i < n - 3; i++ {
        if i > 0 && nums[i] == nums[i - 1] {
            continue
        }
        for j := i + 1; j < n - 2; j++ {
            if j > i + 1 && nums[j] == nums[j - 1] {
                continue
            }
            t := target - nums[i] - nums[j]
            k, l := j+1, n - 1;
            for k < l {
                if nums[k] + nums[l] < t {
                    k++
                } else if nums[k] + nums[l] > t {
                    l--
                } else {
                    result = append(result, []int{nums[i], nums[j], nums[k], nums[l]})
                    for k++; k < l && nums[k] == nums[k-1]; k++ {}
                    for l--; k < l && nums[l] == nums[l+1]; l-- {}
                }
            }
        }
    }
    return result
}
