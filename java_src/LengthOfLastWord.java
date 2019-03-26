class LengthOfLastWord {
    public static void main(String[] args) {
        LengthOfLastWord lw = new LengthOfLastWord();
        System.out.println(lw.lengthOfLastWord("a"));
    }
    public int lengthOfLastWord(String s) {
        if (s == null || s.length() == 0) {
            return 0;
        }

        int l = 0, ptr = s.length() - 1;

        while (ptr >= 0 && s.charAt(ptr) == ' ') {
            ptr--;
        }

        while (ptr >= 0 && s.charAt(ptr) != ' ') {
            l++;
            ptr--;
        }

        return l;
    }
};