class Solution {
    public String convert(String s, int numRows) {
        if (s == null || s.length() < 2 || numRows == 1) {
            return s;
        }
        StringBuilder[] array = new StringBuilder[numRows];
        for (int i = 0; i < numRows; i++) {
            array[i] = new StringBuilder();
        }
        int index = 0, direction = 1;
        for (char c: s.toCharArray()) {
            array[index].append(c);
            index += direction;
            if (index == 0 || index == numRows - 1) {
                direction *= -1;
            }
        }
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < numRows; i++) {
            result.append(array[i]);
        }
        return result.toString();
    }

    public static void main(String[] args) {
        Solution slo = new Solution();
        System.out.println(slo.convert("ABCDEFG", 3));
    }
}
