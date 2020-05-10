func romanToInt(s string) int {
	result, n := 0, len(s)
	s += " "
	for i := 0; i < n; i++ {
		v1 := convert(s[i])
		v2 := convert(s[i+1])
		if v1 < v2 {
			result += v2 - v1
			i++
		} else {
			result += v1
		}
	}
	return result
}

func convert(c byte) int {
	switch c {
	case 'I':
		return 1
	case 'V':
		return 5
	case 'X':
		return 10
	case 'L':
		return 50
	case 'C':
		return 100
	case 'D':
		return 500
	case 'M':
		return 1000
	default:
		return 0
	}
}
