class Solution {
    public int threeSumClosest(int[] nums, int target) {
        int n = nums.length, sum = nums[0] + nums[1] + nums[2], min = Integer.MAX_VALUE;
        Arrays.sort(nums);
        for (int i = 0; i < n - 2; i++) {
            int j = i + 1, k = n - 1;
            while (j < k) {
                int sumT = nums[i] + nums[j] + nums[k];
                int abs = Math.abs(sumT - target);
                if (abs < min) {
                    min = abs;
                    sum = sumT;
                }
                if (sumT < target) {
                    for (j++; j < k && nums[j] == nums[j - 1]; j++) {}
                } else if (sumT > target) {
                    for (k--; j < k && nums[k] == nums[k + 1]; k--) {}
                } else {
                    return target;
                }
            }
        }
        return sum;
    }
}
