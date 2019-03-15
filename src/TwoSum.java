import java.util.HashMap;
import java.util.Map;

public class TwoSum {
    public static void main(String[] args) {

    }

    class Solution {
        public int[] twoSum(int[] nums, int target) {
            Map<Integer, Integer> m = new HashMap<>();
            for (int i = 0; i < nums.length; i++) {
                int j = target - nums[i];
                if (m.containsKey(j)) {
                    return new int[]{m.get(j), i};
                }
                m.put(nums[i], i);
            }
            return new int[]{};
        }
    }
}
