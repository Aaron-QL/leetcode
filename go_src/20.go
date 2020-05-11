func isValid(s string) bool {
    if s == "" {
        return true
    }
    stack := []rune{}
    m := map[rune]rune{
        ')': '(',
        ']': '[',
        '}': '{',
    }
    for _, b := range s {
        if b == '(' || b == '[' || b == '{' {
            stack = append(stack, b)
        } else {
            n := len(stack)
            if n == 0 {
                return false
            }
            if stack[n-1] != m[b] {
                return false
            }
            stack = stack[:n-1]
        }
    }
    return len(stack) == 0
}
