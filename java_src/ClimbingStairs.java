public class ClimbingStairs {
    public static void main(String[] args) {
        ClimbingStairs cs = new ClimbingStairs();
        System.out.println(cs.climbStairs(5));
    }

    public int climbStairs(int n) {
        int[] mem = new int[n + 1];

        return climbStairs(0, n, mem);
    }

    private int climbStairs(int i, int n, int[] mem) {
        if (i > n) {
            return 0;
        }

        if (i == n) {
            return 1;
        }

        if (mem[i] > 0) {
            return mem[i];
        }

        mem[i] = climbStairs(i + 1, n, mem) + climbStairs(i + 2, n, mem);
        return mem[i];
    }

    public int climbStairs2(int n) {
        if (n < 3) {
            return n;
        }

        int[] map = new int[n + 1];
        map[1] = 1;
        map[2] = 2;
        for (int i = 3; i<= n; i++) {
            map[i] = map[i - 2] + map[i - 1];
        }

        return map[n];
    }

    public int climbStairs3(int n) {
        if (n < 3) {
            return n;
        }

        int first = 1;
        int second = 2;
        for (int i = 3; i <= n; i++) {
            int third = first + second;
            first = second;
            second = third;
        }

        return second;
    }
}
