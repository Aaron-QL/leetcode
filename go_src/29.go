func divide(dividend int, divisor int) int {
	if dividend == 0 {
		return 0
	}
	sign := 1
	if dividend < 0 && divisor > 0 || dividend > 0 && divisor < 0 {
		sign = -1
	}
	if dividend < 0 {
		dividend = -dividend
	}
	if divisor < 0 {
		divisor = - divisor
	}

	count := div(dividend, divisor)

	if sign == 1 {
		if count > math.MaxInt32 {
			count = math.MaxInt32
		}
		return count
	} else {
		return -count
	}
}

func div(a, b int) int {
	if a < b {return 0}
	count := 1
	tb := b
	for tb + tb < a {
		tb += tb
		count += count
	}

	return count + div(a - tb, b)
}
