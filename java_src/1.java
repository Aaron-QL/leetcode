class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> m = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            int compoment = target - nums[i];
            if (m.containsKey(compoment)) {
                return new int[]{m.get(compoment), i};
            }
            m.put(nums[i], i);
        }
        return new int[]{};
    }
}
