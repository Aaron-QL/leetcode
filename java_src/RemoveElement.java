import java.util.Arrays;

public class RemoveElement {
    public static void main(String[] args) {
        RemoveElement re = new RemoveElement();
        int[] nums = {3, 3};
        System.out.println(re.removeElement(nums, 5));
        System.out.println(Arrays.toString(nums));
    }
    public int removeElement(int[] nums, int val) {
        if (nums == null || nums.length == 0) {
            return 0;
        }

        int i = 0;
        int n = nums.length;
        while (i < n) {
            if (nums[i] == val) {
                nums[i] = nums[--n];
            } else {
                i++;
            }
        }
        return i;
    }
}
