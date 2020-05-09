class Solution {
    public String longestPalindrome(String s) {
        if (s == null || s.length() < 2) {
            return s;
        }
        int len = s.length();
        boolean[][] isPalindrome = new boolean[len + 1][len + 1];
        String maxSubString = "";
        for (int j = 0; j <= len ; j++) {
            for (int i = j; i >= 0; i--) {
                if (i == j || i + 1 == j) {
                    isPalindrome[i][j] = true;
                } else if (s.charAt(i) == s.charAt(j - 1) && isPalindrome[i+1][j-1]) {
                    isPalindrome[i][j] = true;
                }
                if (i != j && isPalindrome[i][j] && j - i > maxSubString.length()) {
                    maxSubString = s.substring(i, j);
                }
            }
        }

        return maxSubString;
    }
}
