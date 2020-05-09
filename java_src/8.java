class Solution {
   public int myAtoi(String str) {
        if (str == null || str.length() == 0) {
            return 0;
        }

        int index = 0, result = 0, len = str.length(), digit;
        boolean negative = true;
        char[] s = str.toCharArray();
        char c;
        while (index < len && s[index] == ' ') {
            index++;
        }
        if (index == len) {
            return 0;
        }
        if ((c = s[index]) == '+') {
            index++;
        } else if (c == '-') {
            negative = false;
            index++;
        }
        while (index < len && Character.isDigit(s[index])) {
            digit = s[index] - '0';
            if (result > (Integer.MAX_VALUE - digit) / 10) {
                return negative ? Integer.MAX_VALUE : Integer.MIN_VALUE;
            }
            result = result * 10 + digit;
            index++;
        }

        return negative ? result : -result;
    }
}
