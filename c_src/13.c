int convert(char);

int romanToInt(char * s){
    int ans = 0;
    int v1, v2, temp;
    for (int i = 0; s[i] != NULL; i++) {
        v1 = convert(s[i]);
        v2 = convert(s[i+1]);
        if (v1 < v2) {
            ans += v2 - v1;
            i++;
        } else {
            ans += v1;
        }
    }

    return ans;
}

int convert(char s) {
    switch (s) {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0;
    }
}
