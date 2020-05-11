
var phone = map[string]string{
	"2": "abc",
	"3": "def",
	"4": "ghi",
	"5": "jkl",
	"6": "mno",
	"7": "pqrs",
	"8": "tuv",
	"9": "xyz",
}

var result = []string{}

func letterCombinations(digits string) []string {
	if len(digits) != 0 {
		backTrack("", digits)
	}
	return result
}

func backTrack(combination, nextDigit string) {
	if len(nextDigit) == 0 {
		result = append(result, combination)
		return
	}

	letters := phone[nextDigit[0:1]]
	for _, c := range letters {
		backTrack(combination + string(c), nextDigit[1:])
	}
}

func main() {
	fmt.Println(letterCombinations(""))
}
