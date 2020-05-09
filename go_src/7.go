func reverse(x int) int {
    var val int64 = 0
    t := int64(x)
    for {
        val = val * 10 + t % 10
        t /= 10
        if t == 0 {
            break
        }
    }
    if val > math.MaxInt32 || val < math.MinInt32 {
        return 0
    } else {
        return int(val)
    }
}
