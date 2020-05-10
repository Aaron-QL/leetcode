func intToRoman(num int) string {
    one := []string{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"}
    two := []string{"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"}
    three := []string{"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"}
    four := []string{"", "M", "MM", "MMM"}

    return four[num / 1000] + three[num % 1000 / 100] + two[num % 100 / 10] + one[num % 10]
}
