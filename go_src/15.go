func threeSum(nums []int) [][]int {
    sort.Ints(nums)
    var result [][]int
    for i := 0; i < len(nums) - 2; i++ {
        if i > 0 && nums[i] == nums[i - 1] {
            continue
        }
        target := -nums[i]
        j, k := i + 1, len(nums) - 1
        for j < k {
            if sum := nums[j] + nums[k]; sum < target {
                j++
            } else if sum > target {
                k--
            } else {
                result = append(result, []int{nums[i], nums[j], nums[k]})
                for j++; j < k && nums[j] == nums[j-1]; j++ {}
                for k--; k > j && nums[k] == nums[k+1]; k-- {}
            }
        }
    }
    return result
}
