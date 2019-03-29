public class Sqrt {

    public static void main(String[] args) {
        Sqrt s = new Sqrt();
        System.out.println(s.mySqrt(10));
    }

    public int mySqrt(int x) {
        long low = 0;
        long high = x;
        while (low <= high) {
            long mid = (low + high) / 2;
            long pow = mid * mid;
            if (pow == x) {
                return (int) mid;
            } else if (pow < x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return (int) high;
    }
}
