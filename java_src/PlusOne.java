import java.util.Arrays;

public class PlusOne {

    public static void main(String[] args) {
        PlusOne po = new PlusOne();
        int[] a = {8, 9, 9, 9};
        System.out.println(Arrays.toString(po.plusOne(a)));
    }

    public int[] plusOne(int[] digits) {
        int carry = 0;
        int ptr = digits.length - 1;
        while (ptr >= 0) {
            if (digits[ptr] == 9) {
                carry = 1;
                digits[ptr--] = 0;
            } else {
                digits[ptr]++;
                carry = 0;
                break;
            }
        }

        if (carry == 1) {
            int[] t = new int[digits.length + 1];
            t[0] = 1;
            for (int i = 1; i < t.length; i++) {
                t[i] = 0;
            }
            digits = t;
        }

        return digits;
    }
}