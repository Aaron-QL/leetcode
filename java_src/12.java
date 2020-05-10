class Solution {
    public String intToRoman(int num) {
        String[] one = new String[] {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        String[] two = new String[] {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        String[] three = new String[] {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        String[] four = new String[] {"", "M", "MM", "MMM"};

        return four[num / 1000] + three[num % 1000 / 100] + two[num % 100 / 10] + one[num % 10];
    }
}
