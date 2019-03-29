public class AddBinary {
    public static void main(String[] args) {
        AddBinary ab = new AddBinary();
        System.out.println(ab.addBinary("10101", "1111"));
    }

    public String addBinary(String a, String b) {
        int carry = 0;
        int pa = a.length() - 1;
        int pb = b.length() - 1;
        StringBuilder sb = new StringBuilder();
        while (pa >= 0 || pb >= 0) {
            int sum = carry;
            if (pa >= 0) {
                sum += a.charAt(pa--) - '0';
            }
            if (pb >= 0) {
                sum += b.charAt(pb--) - '0';
            }
            sb.append(sum % 2);
            carry = sum / 2;
        }
        if (carry != 0) {
            sb.append(carry);
        }
        return sb.reverse().toString();
    }
}
