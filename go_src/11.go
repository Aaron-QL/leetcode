func maxArea(height []int) int {
    i, j, maxArea := 0, len(height) - 1, 0
    var shorterSide, area int
    for i < j {
        if height[i] < height[j] {
            area = height[i] * (j - i)
        } else {
            area = height[j] * (j - i)
        }
        maxArea = max(maxArea, area)

        if height[i] < height[j] {
            shorterSide = height[i]
            for i++; i < j && height[i] <= shorterSide; i++ {}
        } else {
            shorterSide = height[j]
            for j--; j> i && height[j] <= shorterSide; j-- {}
        }
    }

    return maxArea
}

func max(x, y int) int {
    if x > y {
        return x
    } else {
        return y
    }
}
