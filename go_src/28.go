func strStr(haystack string, needle string) int {
	len1, len2 := len(haystack), len(needle)
	if len1 < len2 {
		return -1
	}
	if len2 == 0 {
		return 0
	}
	index := 0
	for index <= len1 - len2 {
		curIndex := 0
		for ; curIndex < len2; curIndex++ {
			if haystack[index + curIndex] != needle[curIndex] {
				break
			}
		}
		if curIndex == len2 {
			return index
		}
		index++
	}
	return -1
}
