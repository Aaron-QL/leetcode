func lengthOfLongestSubstring(s string) int {
    n := len(s)
    if n == 0 {return 0}
    m := make(map[byte]int)
    maxLen := 0
    for left, right := 0, 0; right < n; right++ {
        if p, ok := m[s[right]]; ok {
            left = int(math.Max(float64(left), float64(p)))
        }
        m[s[right]] = right + 1
        maxLen = int(math.Max(float64(maxLen), float64(right - left + 1)))
    }
    return maxLen
}
