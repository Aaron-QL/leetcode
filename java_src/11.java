class Solution {
    public int maxArea(int[] height) {
        if (height.length == 0) {
            return 0;
        }
        int left = 0, right = height.length - 1, maxArea = 0, lowerHeight;
        while (left < right) {
            lowerHeight = Math.min(height[left], height[right]);
            maxArea = Math.max((right - left) * lowerHeight, maxArea);
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return maxArea;
    }
}
