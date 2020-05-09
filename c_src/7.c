int reverse(int x){
    long val = 0;
    do {
        val = val * 10 + x % 10;
    } while (x /= 10);
    return (val > INT_MAX || val < INT_MIN) ? 0 : val;
}
