func countAndSay(n int) string {
    result := "1"
    for i := 1; i < n; i++ {
        s := []byte(result)
        l := len(s)
        temp := ""
        flag := s[0]
        count := 1
        for i := 1; i < l; i++ {
            if s[i] == flag {
                count++
            } else {
                temp += fmt.Sprintf("%d%c", count, flag)
                flag = s[i]
                count = 1
            }
        }
        temp += fmt.Sprintf("%d%c", count, flag)
        result = temp
    }

    return result
}
