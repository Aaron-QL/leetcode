func convert(s string, numRows int) string {
	n := len(s)
	if n < 3 || numRows == 1 {
		return s
	}
	index, direction := 0, 1
	container := make([]string, numRows)
	for i := 0; i < n; i++ {
		container[index] += string(s[i])
		index += direction
		if index == 0 || index == numRows - 1 {
			direction *= -1
		}
	}
	result := ""
	for _, c := range container {
		result += c
	}

	return result
}
