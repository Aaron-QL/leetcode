
int reverse(int x){
    long val = 0;
    do {
        val = val * 10 + x % 10;
        if (val < INT_MIN / 10 || val > INT_MAX / 10) {
            return 0;
        }
    } while (x /= 10);
    return (val > INT_MAX || val < INT_MIN) ? 0 : val;
}
