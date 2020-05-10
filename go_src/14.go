func longestCommonPrefix(strs []string) string {
	n := len(strs)
	if n == 0 {
		return ""
	}
	prefix := strs[0]
	for i := 1; i < n; i++ {
		for !strings.HasPrefix(strs[i], prefix) {
			prefix = prefix[:len(prefix) - 1]
		}
	}
	return prefix
}
