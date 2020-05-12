func generateParenthesis(n int) []string {
	if n != 0 {
		backTrack("", 0, 0, n)
	}
	return result
}

var result = []string{}

func backTrack(combination string, open, close, max int) {
	if len(combination) == max * 2 {
		result = append(result, combination)
		return
	}

	if open < max - close {
		backTrack(combination + "(", open+1, close, max)
	}

	if open > 0 {
		backTrack(combination + ")", open-1, close+1, max)
	}
}

func main() {
	fmt.Println(generateParenthesis(1))
}
