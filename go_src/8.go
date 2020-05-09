func myAtoi(str string) int {
	n := len(str)

	index, sign, result := 0, 1, 0
	for index < n && str[index] == ' ' {
		index++
	}

	if index == n {
		return 0
	}

	if str[index] == '+' {
		index++
	} else if str[index] == '-' {
		sign = -1
		index++
	}

	for ;index < n && str[index] >= '0' && str[index] <= '9'; index++ {
		digit := int(str[index] - '0')
		if result > (int(math.MaxInt32) - digit) / 10 {
			if sign == 1 {
				return int(math.MaxInt32)
			} else {
				return int(math.MinInt32)
			}
		}
		result = result * 10 + digit
	}

	return sign * result
}
