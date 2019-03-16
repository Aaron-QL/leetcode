public class RomanToInteger {
    public static void main(String[] args) {
        RomanToInteger r = new RomanToInteger();
        System.out.print(r.romanToInt("MCMXCIV"));
    }
    public int romanToInt(String s) {
        int ptr = s.length() - 1;
        int ret = 0;
        while (ptr >= 0) {
            char c = s.charAt(ptr);
            switch (c) {
                case 'I':
                    ret += 1;
                    ptr--;
                    break;
                case 'V':
                    if (ptr > 0 && s.charAt(ptr - 1) == 'I') {
                        ret += 4;
                        ptr -= 2;
                    } else {
                        ret += 5;
                        ptr--;
                    }
                    break;
                case 'X':
                    if (ptr > 0 && s.charAt(ptr - 1) == 'I') {
                        ret += 9;
                        ptr -= 2;
                    } else {
                        ret += 10;
                        ptr--;
                    }
                    break;
                case 'L':
                    if (ptr > 0 && s.charAt(ptr - 1) == 'X') {
                        ret += 40;
                        ptr -= 2;
                    } else {
                        ret += 50;
                        ptr--;
                    }
                    break;
                case 'C':
                    if (ptr > 0 && s.charAt(ptr - 1) == 'X') {
                        ret += 90;
                        ptr -= 2;
                    } else {
                        ret += 100;
                        ptr--;
                    }
                    break;
                case 'D':
                    if (ptr > 0 && s.charAt(ptr - 1) == 'C') {
                        ret += 400;
                        ptr -= 2;
                    } else {
                        ret += 500;
                        ptr--;
                    }
                    break;
                case 'M':
                    if (ptr > 0 && s.charAt(ptr - 1) == 'C') {
                        ret += 900;
                        ptr -= 2;
                    } else {
                        ret += 1000;
                        ptr--;
                    }
                    break;
            }
        }
        return ret;
    }
}
