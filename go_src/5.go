func longestPalindrome(s string) string {
    n := len(s)
    if n < 2 {return s}
    isLongestPalindrome := make([][]bool, n + 1)
    maxString := ""
    for r := 0; r <= n; r++ {
        isLongestPalindrome[r] = make([]bool, n + 1)
        for l := r; l >= 0; l-- {
            if l == r || l + 1 == r {
                isLongestPalindrome[l][r] = true
            } else if s[l] == s[r-1] && isLongestPalindrome[l+1][r-1] {
                isLongestPalindrome[l][r] = true
            }
            if l != r && isLongestPalindrome[l][r] && r - l > len(maxString) {
                maxString = s[l:r]
            }
        }
    }
    return maxString
}
